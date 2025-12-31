#include "JobBoard.h"
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

JobBoard::~JobBoard() {
    for (auto job : jobs)
        delete job;
}
