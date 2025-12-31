#include "Job.h"
#include "Application.h"

Job::Job(const string& title, const string& company)
    : title(title), company(company) {
}

void Job::addApplication(Application* app) {
    applications.push_back(app);
}

const std::vector<Application*>& Job::getApplications() const {
    return applications;
}

Job::~Job() {
}
