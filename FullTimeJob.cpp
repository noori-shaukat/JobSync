#include "FullTimeJob.h"
#include <iostream>
using namespace std;

FullTimeJob::FullTimeJob(const string& title, const string& company, double salary)
    : Job(title, company), annualSalary(salary) {
}

void FullTimeJob::display() const {
    cout << "Full-Time Job\n";
    cout << "Title: " << title << endl;
    cout << "Company: " << company << endl;
    cout << "Annual Salary: $" << annualSalary << endl;
    cout << "Status: " << (isOpen ? "Open" : "Closed") << endl;
    cout << endl;
}

double FullTimeJob::getMonthlyPay() const {
    return annualSalary / 12;
}
