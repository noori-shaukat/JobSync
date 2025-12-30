#include "Application.h"
#include "Applicant.h"
#include "Job.h"
#include <iostream>

using namespace std;

Application::Application(Applicant* applicant, Job* job)
    : applicant(applicant), job(job) {
}

void Application::display() const {
    cout << "Application Details:\n";
    cout << "Applicant:\n";
    applicant->display();
    cout << "Applied To Job:\n";
    job->display();
}
