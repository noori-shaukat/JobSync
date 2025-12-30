#include "PartTimeJob.h"
#include <iostream>
using namespace std;

PartTimeJob::PartTimeJob(const string& title, const string& company,
    double rate, int hours)
    : Job(title, company), hourlyRate(rate), hoursPerWeek(hours) {
}

void PartTimeJob::display() const {
    cout << "Part-Time Job\n";
    cout << "Title: " << title << endl;
    cout << "Company: " << company << endl;
    cout << "Hourly Rate: $" << hourlyRate << endl;
    cout << "Hours/Week: " << hoursPerWeek << endl;
}

double PartTimeJob::getPay() const {
    return hourlyRate * hoursPerWeek * 4;  // monthly estimate
}
