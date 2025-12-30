#include "Applicant.h"
#include "Application.h"
#include "Job.h"
#include <iostream>

using namespace std;

Applicant::Applicant(const string& name, const string& email, const string& resume)
    : User(name, email), resume(resume) {
}

void Applicant::apply(Job* job) {
    applications.push_back(new Application(this, job));
}

void Applicant::displayApplications() const {
    for (auto app : applications) {
        app->display();
        cout << endl;
    }
}

void Applicant::display() const {
    cout << "Applicant Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Resume: " << resume << endl;
}

string Applicant::getRole() const {
    return "Applicant";
}

Applicant::~Applicant() {
    for (auto app : applications)
        delete app;
}
