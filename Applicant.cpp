#include "Applicant.h"
#include "Application.h"
#include "Job.h"
#include <iostream>

using namespace std;

Applicant::Applicant(const string& name, const string& email)
    : User(name, email) {
}

bool Applicant::apply(Job* job) {
    if (!job->getIsOpen()) {
        cout << "Job is closed.\n";
        return false;
    }
    
    for (auto app : applications) {
        if (app->getJob() == job) {
            cout << "Already applied to this job.\n";
            return false;
        }
    }
    Application* app = new Application(this, job);
    job->addApplication(app);
    applications.push_back(app);

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
        app->displayForApplicant();
        cout << endl;
    }
}

const std::vector<Application*>& Applicant::getApplications() const {
    return applications;
}

vector<Application*> Applicant::getApplicationsByStatus(ApplicationStatus status) const {
    vector<Application*> result;
    for (auto app : applications) {
        if (app->getStatus() == status) {
            result.push_back(app);
        }
    }
    return result;
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

Applicant::~Applicant() = default;

