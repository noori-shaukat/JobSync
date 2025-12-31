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

void Application::display() const {
    job->display();

    cout << "Status: ";
    switch (status) {
    case ApplicationStatus::Submitted:   cout << "Submitted"; break;
    case ApplicationStatus::Viewed:      cout << "Viewed"; break;
    case ApplicationStatus::Shortlisted: cout << "Shortlisted"; break;
    case ApplicationStatus::Rejected:    cout << "Rejected"; break;
    case ApplicationStatus::Hired:       cout << "Hired"; break;
    }
    cout << endl;
}
