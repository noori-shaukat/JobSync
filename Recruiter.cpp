#include "Application.h"
#include "Recruiter.h"
#include "Applicant.h"
#include <iostream>
using namespace std;

Recruiter::Recruiter(const string& name, const string& email, const string& company)
    : User(name, email), company(company) {
}

void Recruiter::display() const {
    cout << "Recruiter Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Company: " << company << endl;
}

void Recruiter::postJob(Job* job, JobBoard& board) {
    postedJobs.push_back(job);
    board.addJob(job);
}

void Recruiter::reviewApplications() const {
    cout << "\nApplications for company: " << company << endl;

    for (auto job : postedJobs) {
        cout << "\nJob: ";
        job->display();

        for (auto applicantApp : job->getApplications()) {
            applicantApp->displayForRecruiter();
        }
    }
}

void Recruiter::updateApplicationStatus(Application* app, ApplicationStatus status) {
    if (!app->getJob()->getIsOpen()) {
        cout << "Cannot change application status: Job is closed.\n";
        return;
    }

    if (status == ApplicationStatus::Hired) {
        app->getJob()->hireApplicant(app);
        cout << app->getApplicant()->getName() << " has been hired for this job.\n";
    }
    else {
        app->setStatus(status);
        cout << "Status updated.\n";
    }
}



string Recruiter::getRole() const {
    return "Recruiter";
}

string Recruiter::getCompany() const {
    return company;
}

void Recruiter::reviewShortlisted() const {
    for (auto job : postedJobs) {
        cout << "\nShortlisted for job:\n";
        job->display();

        for (auto app : job->getApplicationsByStatus(ApplicationStatus::Shortlisted)) {
            app->displayForRecruiter();
        }
    }
}

void Recruiter::closeJob(Job* job) {
    job->closeJob();
}

void Recruiter::openJob(Job* job) {
    job->openJob();
}

void Recruiter::displayPostedJobs() const {
    const auto& jobs = getPostedJobs();
    if (jobs.empty()) {
        cout << "No jobs posted yet.\n";
        return;
    }

    int idx = 1;
    for (auto* job : jobs) {
        cout << idx++ << ". ";
        job->display();
    }
}

void Recruiter::displayApplicationsForJob(Job* job) const {
    const auto& apps = job->getApplications();
    if (apps.empty()) {
        cout << "No applications for this job.\n";
        return;
    }

    int idx = 1;
    for (auto* app : apps) {
        cout << idx++ << ". ";
        app->displayForRecruiter();
    }
}
