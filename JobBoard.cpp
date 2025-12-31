#include "JobBoard.h"
#include <algorithm>
#include <iostream>

using namespace std;

void JobBoard::addJob(Job* job) {
    jobs.push_back(job);
}

const std::vector<Job*>& JobBoard::getJobs() const {
    return jobs;
}

void JobBoard::displayAllJobs() const {
    cout << "\n--- Job Listings ---\n";
    int index = 1;
    for (auto job : jobs) {
        cout << index++ << ". ";
        job->display();
        cout << endl;
    }
}

vector<Job*> JobBoard::getJobsByCompany(const string& company) const {
    vector<Job*> result;
    for (auto job : jobs) {
        if (job->getCompany() == company) {
            result.push_back(job);
        }
    }
    return result;
}

vector<Job*> JobBoard::getOpenJobs() const {
    vector<Job*> result;
    for (auto job : jobs) {
        if (job->getIsOpen()) {
            result.push_back(job);
        }
    }
    return result;
}

void JobBoard::sortByTitle() {
    std::sort(jobs.begin(), jobs.end(), [](Job* a, Job* b) {
        return a->getTitle() < b->getTitle();
        });
}

void JobBoard::sortByCompany() {
    std::sort(jobs.begin(), jobs.end(), [](Job* a, Job* b) {
        return a->getCompany() < b->getCompany();
        });
}

void JobBoard::sortByPayDescending() {
    std::sort(jobs.begin(), jobs.end(), [](Job* a, Job* b) {
        return a->getMonthlyPay() > b->getMonthlyPay();
        });
}

JobBoard::~JobBoard() {
    for (Job* job : jobs)
        delete job;
}
