#ifndef FULLTIMEJOB_H
#define FULLTIMEJOB_H

#include "Job.h"

class FullTimeJob : public Job {
private:
    double annualSalary;

public:
    FullTimeJob(const string& title, const string& company, double salary);

    void display() const override;
    double getPay() const override;
};

#endif
