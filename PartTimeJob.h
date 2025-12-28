#ifndef PARTTIMEJOB_H
#define PARTTIMEJOB_H

#include "Job.h"

class PartTimeJob : public Job {
    double hourlyRate;
    int hoursPerWeek;

public:
    PartTimeJob(const string& title, const string& company,
        double rate, int hours);

    void display() const override;
    double getPay() const override;
};

#endif
