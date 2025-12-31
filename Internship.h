#ifndef INTERNSHIP_H
#define INTERNSHIP_H

#include "Job.h"

class Internship : public Job {
private:
    double monthlyStipend;

public:
    Internship(const string& title, const string& company, double stipend);

    void display() const override;
    double getMonthlyPay() const override;
};

#endif
