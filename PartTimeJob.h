#ifndef PARTTIMEJOB_H
#define PARTTIMEJOB_H

#include "Job.h"

class PartTimeJob : public Job {
    double hourlyRate;
    int hoursPerWeek;

public:
    PartTimeJob(const string& title, const string& company,
        double rate);

    void display() const override;
    double getMonthlyPay() const override;
};

#endif
