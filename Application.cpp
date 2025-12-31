#include "Application.h"
#include "Applicant.h"
#include "Job.h"
#include <iostream>

using namespace std;

Application::Application(Applicant* applicant, Job* job)
    : applicant(applicant), job(job), status(ApplicationStatus::Submitted) {}

Applicant* Application::getApplicant() const {
    return applicant;
}

Job* Application::getJob() const {
    return job;
}

void Application::setStatus(ApplicationStatus newStatus) {
    status = newStatus;
}

ApplicationStatus Application::getStatus() const {
    return status;
}

string Application::statusToString(ApplicationStatus status) const {
    switch (status) {
    case ApplicationStatus::Submitted:   return "Submitted";
    case ApplicationStatus::Viewed:      return "Viewed";
    case ApplicationStatus::Shortlisted: return "Shortlisted";
    case ApplicationStatus::Rejected:    return "Rejected";
    case ApplicationStatus::Hired:       return "Hired";
    default:                             return "Unknown";
    }
}

void Application::display() const {
    cout << "Applicant Details:\n";
    applicant->display();
    cout << "Job Applied To:";
    job->display();

    cout << "Status: " << statusToString(status) << endl;

    cout << endl;
}

void Application::displayForRecruiter() const {
    cout << "Applicant Name: " << applicant->getName() << endl;
    cout << "Email: " << applicant->getEmail() << endl;
    cout << "Status: " << statusToString(status) << endl;
    cout << endl;
}

void Application::displayForApplicant() const {
    cout << "Job Applied To:\n";
    job->display();
    cout << "Status: " << statusToString(status) << endl << endl;

}
