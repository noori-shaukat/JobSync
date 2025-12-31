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

    ~JobBoard();
};

#endif
