#include "Job.h"
#include "Application.h"

Job::Job(const string& title, const string& company)
    : title(title), company(company), isOpen(true) {
}

bool Job::getIsOpen() const {
    return isOpen;
}

void Job::closeJob() {
    isOpen = false;
}

void Job::openJob() {
    isOpen = true;
}

std::string Job::getTitle() const {
    return title;
}

std::string Job::getCompany() const {
    return company;
}

void Job::addApplication(Application* app) {
    applications.push_back(app);
}

const std::vector<Application*>& Job::getApplications() const {
    return applications;
}

vector<Application*> Job::getApplicationsByStatus(ApplicationStatus status) const {
    vector<Application*> result;
    for (auto app : applications) {
        if (app->getStatus() == status) {
            result.push_back(app);
        }
    }
    return result;
}

void Job::hireApplicant(Application* hiredApp) {
    // Close the job
    closeJob();

    // Update statuses
    for (auto* app : applications) {
        if (app == hiredApp) {
            app->setStatus(ApplicationStatus::Hired);
        }
        else {
            app->setStatus(ApplicationStatus::Rejected);
        }
    }
}

Job::~Job() {
    for (Application* app : applications) {
        delete app;
    }
}
