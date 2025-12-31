#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Applicant.h"
#include "Recruiter.h"
#include "JobBoard.h"
#include "FullTimeJob.h"
#include "PartTimeJob.h"
#include "Internship.h"
#include "Application.h"

using namespace std;

int main() {
    vector<Applicant*> applicants;
    vector<Recruiter*> recruiters;

    // Applicants
    applicants.push_back(new Applicant("Noori", "noori@email.com"));
    applicants.push_back(new Applicant("Ahmed", "ahmed@email.com"));
    applicants.push_back(new Applicant("Sara", "sara@email.com"));

    // Recruiters
    recruiters.push_back(new Recruiter("Ali", "ali@company.com", "Google"));
    recruiters.push_back(new Recruiter("Fatima", "fatima@company.com", "Microsoft"));
    
    JobBoard board;

	//recruiters post jobs
    Recruiter* ali = recruiters[0];
    ali->postJob(new FullTimeJob("Software Engineer", "Google", 120000), board);
    ali->postJob(new Internship("Backend Intern", "Google", 1500), board);
    ali->postJob(new PartTimeJob("Support Engineer", "Google", 30), board);

    Recruiter* fatima = recruiters[1];
    fatima->postJob(new FullTimeJob("Data Scientist", "Microsoft", 130000), board);
    fatima->postJob(new PartTimeJob("QA Tester", "Microsoft", 25), board);

	//applicants apply to jobs
    applicants[0]->apply(board.getJobs()[0]);
    applicants[0]->apply(board.getJobs()[1]);

    applicants[1]->apply(board.getJobs()[0]);
    applicants[1]->apply(board.getJobs()[3]);

    applicants[2]->apply(board.getJobs()[4]);

	//recruiters update application statuses
    ali->updateApplicationStatus(board.getJobs()[0]->getApplications()[0], ApplicationStatus::Shortlisted);
    ali->updateApplicationStatus(board.getJobs()[0]->getApplications()[1], ApplicationStatus::Rejected);
    fatima->updateApplicationStatus(board.getJobs()[4]->getApplications()[0], ApplicationStatus::Hired);

	//Main interaction loop
    bool running = true;
    while (running) {
        cout << "\n--- Job Application System ---\n";
        cout << "1. Login as Applicant\n";
        cout << "2. Login as Recruiter\n";
        cout << "3. Exit\n";
        cout << "Select option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            // Applicant login
            cout << "Enter email: ";
            string email;
            cin >> email;

            Applicant* currentApplicant = nullptr;
            for (auto a : applicants) {
                if (a->getEmail() == email) {
                    currentApplicant = a;
                    break;
                }
            }

            if (!currentApplicant) {
                cout << "Applicant not found.\n";
                continue;
            }

            bool loggedIn = true;
            while (loggedIn) {
                cout << "\n--- Applicant Menu ---\n";
                cout << "1. View Open Jobs\n";
                cout << "2. Sort Jobs\n";
                cout << "3. Apply to Job\n";
                cout << "4. View My Applications\n";
                cout << "5. View Applications by Status\n";
                cout << "6. Logout\n";
                cout << "Select option: ";
                int appChoice;
                cin >> appChoice;

                switch (appChoice) {
                case 1: {
                    board.displayAllJobs();
                    break;
                }
                case 2: {
                    cout << "Sort Jobs By:\n";
                    cout << "1. Title\n2. Company\n3. Pay (high to low)\n";
                    int choice; cin >> choice;

                    switch (choice) {
                    case 1: board.sortByTitle(); break;
                    case 2: board.sortByCompany(); break;
                    case 3: board.sortByPayDescending(); break;
                    default:
                        cout << "Invalid option.\n";
                    }

                    board.displayAllJobs();
                    break;
                }
                case 3: {
                    cout << "\nEnter job number to apply: ";
                    int jobIndex;
                    cin >> jobIndex;
                    auto& jobs = board.getJobs();
                    if (jobIndex < 1 || jobIndex >(int)jobs.size()) {
                        cout << "Invalid job number.\n";
                    }
                    else {
                        currentApplicant->apply(jobs[jobIndex - 1]);
                    }
                    break;
                }
                case 4:
                    currentApplicant->displayApplications();
                    break;
                case 5: {
                    cout << "Enter status (0:Submitted, 1:Viewed, 2:Shortlisted, 3:Rejected, 4:Hired): ";
                    int statusInt;
                    cin >> statusInt;
                    auto filteredApps = currentApplicant->getApplicationsByStatus(
                        static_cast<ApplicationStatus>(statusInt));
                    for (auto app : filteredApps)
                        app->displayForApplicant();
                    break;
                }
                case 6:
                    loggedIn = false;
                    break;
                default:
                    cout << "Invalid option.\n";
                }
            }

        }
        else if (choice == 2) {
            // Recruiter login
            cout << "Enter email: ";
            string email;
            cin >> email;

            Recruiter* currentRecruiter = nullptr;
            for (auto r : recruiters) {
                if (r->getEmail() == email) {
                    currentRecruiter = r;
                    break;
                }
            }

            if (!currentRecruiter) {
                cout << "Recruiter not found.\n";
                continue;
            }

            bool loggedIn = true;
            while (loggedIn) {
                cout << "\n--- Recruiter Menu ---\n";
                cout << "1. Post Full-Time Job\n";
                cout << "2. Post Internship\n";
                cout << "3. Post Part-Time Job\n";
                cout << "4. Review Applications\n";
                cout << "5. Review Shortlisted Applicants\n";
                cout << "6. Update Application Status\n";
                cout << "7. Open/Close Job\n";
                cout << "8. Logout\n";
                cout << "Select option: ";
                int recChoice;
                cin >> recChoice;

                switch (recChoice) {
                case 1: {
                    string title; double salary;
                    cout << "Enter job title: ";
                    cin.ignore(); getline(cin, title);
                    cout << "Enter annual salary: ";
                    cin >> salary;
                    currentRecruiter->postJob(new FullTimeJob(title, currentRecruiter->getCompany(), salary), board);
                    break;
                }
                case 2: {
                    string title; double stipend;
                    cout << "Enter internship title: ";
                    cin.ignore(); getline(cin, title);
                    cout << "Enter monthly stipend: ";
                    cin >> stipend;
                    currentRecruiter->postJob(new Internship(title, currentRecruiter->getCompany(), stipend), board);
                    break;
                }
                case 3: {
                    string title; double rate;
                    cout << "Enter job title: ";
                    cin.ignore(); getline(cin, title);
                    cout << "Enter hourly rate: ";
                    cin >> rate;
                    currentRecruiter->postJob(new PartTimeJob(title, currentRecruiter->getCompany(), rate), board);
                    break;
                }
                case 4:
                    currentRecruiter->reviewApplications();
                    break;
                case 5:
                    currentRecruiter->reviewShortlisted();
                    break;
                case 6: {
                    currentRecruiter->displayPostedJobs();
                    cout << "Enter job number: ";
                    int jobNum; cin >> jobNum;

                    auto& jobs = currentRecruiter->getPostedJobs();
                    if (jobNum < 1 || jobNum >(int)jobs.size()) {
                        cout << "Invalid job number.\n";
                        break;
                    }
                    Job* job = jobs[jobNum - 1];

                    currentRecruiter->displayApplicationsForJob(job);
                    cout << "Enter applicant number: ";
                    int appNum; cin >> appNum;

                    auto apps = job->getApplications();
                    if (appNum < 1 || appNum >(int)apps.size()) {
                        cout << "Invalid applicant number.\n";
                        break;
                    }
                    Application* app = apps[appNum - 1];

                    cout << "Enter new status (0:Submitted, 1:Viewed, 2:Shortlisted, 3:Rejected, 4:Hired): ";
                    int statusInt; cin >> statusInt;
                    currentRecruiter->updateApplicationStatus(app, static_cast<ApplicationStatus>(statusInt));

                    break;
                }
                case 7: {
                    currentRecruiter->displayPostedJobs();
                    cout << "Enter job number to open/close: ";
                    int jobNum; cin >> jobNum;

                    Job* job = currentRecruiter->getPostedJobs()[jobNum - 1];
                    cout << "1. Open\n2. Close\nSelect: ";
                    int choice; cin >> choice;
                    if (choice == 1) {
                        currentRecruiter->openJob(job);
                        break;
                    }
                    else if (choice == 2) {
                        currentRecruiter->closeJob(job);
                        break;
                    }
                    else cout << "Invalid choice.\n";
                }
                case 8:
                    loggedIn = false;
                    break;
                default:
                    cout << "Invalid option.\n";
                }
            }

        }
        else if (choice == 3) {
            running = false;
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    // Clean up dynamically allocated memory
    for (auto a : applicants) delete a;
    for (auto r : recruiters) delete r;
    for (auto job : board.getJobs()) delete job;

    cout << "Exiting program.\n";
    return 0;
}
