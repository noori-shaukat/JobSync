#ifndef JOBBOARD_H
#define JOBBOARD_H

#include <vector>
#include "Job.h"

class JobBoard {
private:
    std::vector<Job*> jobs;

public:
    void addJob(Job* job);
    const std::vector<Job*>& getJobs() const;
    void displayAllJobs() const;

    vector<Job*> getJobsByCompany(const string& company) const;
    vector<Job*> getOpenJobs() const;

    void sortByTitle();
    void sortByCompany();
    void sortByPayDescending();

    ~JobBoard();
};

#endif
