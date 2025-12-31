#include "PartTimeJob.h"
#include <iostream>
using namespace std;

PartTimeJob::PartTimeJob(const string& title, const string& company, double rate)
    : Job(title, company), hourlyRate(rate), hoursPerWeek(20) {
}

void PartTimeJob::display() const {
    cout << "Part-Time Job\n";
    cout << "Title: " << title << endl;
    cout << "Company: " << company << endl;
    cout << "Hourly Rate: $" << hourlyRate << endl;
    cout << "Hours/Week: " << hoursPerWeek << endl;
    cout << "Status: " << (isOpen ? "Open" : "Closed") << endl;
    cout << endl;
}

double PartTimeJob::getMonthlyPay() const {
    return hourlyRate * hoursPerWeek * 4; 
}
