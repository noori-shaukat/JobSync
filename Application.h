#ifndef APPLICATION_H
#define APPLICATION_H

#include "Applicant.h"
#include "Job.h"

class Application {
private:
    Applicant* applicant;
    Job* job;

public:
    Application(Applicant* applicant, Job* job);

    void display() const;
};

#endif
