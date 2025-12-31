#include "Applicant.h"
#include "Application.h"
#include "Job.h"
#include <iostream>

using namespace std;

Applicant::Applicant(const string& name, const string& email)
    : User(name, email) {
}

bool Applicant::apply(Job* job) {
    for (auto app : applications) {
        if (app->getJob() == job) {
            cout << "Already applied to this job.\n";
            return false;
        }
    }

    Application* newApp = new Application(this, job);
    applications.push_back(newApp);
    job->addApplication(newApp);

    return true;
}

Profile& Applicant::getProfile() {
    return profile;
}

void Applicant::displayApplications() const {
    cout << "Applicant: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "\nApplied Jobs:\n";

    if (applications.empty()) {
        cout << "No applications yet.\n";
        return;
    }

    int count = 1;
    for (auto app : applications) {
        cout << count++ << ". ";
        app->display();
        cout << endl;
    }
}

const std::vector<Application*>& Applicant::getApplications() const {
    return applications;
}


void Applicant::display() const {
    cout << "Applicant Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "---- Profile ----" << endl;
    profile.display();
}

string Applicant::getRole() const {
    return "Applicant";
}

Applicant::~Applicant() {
    for (auto app : applications)
        delete app;
}
