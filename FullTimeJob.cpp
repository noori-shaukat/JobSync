#include "FullTimeJob.h"
#include <iostream>
using std::cout;
using std::endl;

FullTimeJob::FullTimeJob(const string& title,
    const string& company,
    double salary)
    : Job(title, company), annualSalary(salary) {
}

void FullTimeJob::display() const {
    cout << "Full-Time Job\n";
    cout << "Title: " << title << endl;
    cout << "Company: " << company << endl;
    cout << "Annual Salary: $" << annualSalary << endl;
}

double FullTimeJob::getPay() const {
    return annualSalary;
}
