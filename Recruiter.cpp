#include "Recruiter.h"
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
            applicantApp->display();
        }
    }
}

void Recruiter::updateApplicationStatus(Application* app, ApplicationStatus status) {
    app->setStatus(status);
}


string Recruiter::getRole() const {
    return "Recruiter";
}

Recruiter::~Recruiter() {
    for (auto job : postedJobs)
        delete job;
}
