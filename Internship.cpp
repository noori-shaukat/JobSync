#include "Internship.h"

#include <iostream>
using std::cout;
using std::endl;

Internship::Internship(const string& title,
    const string& company,
    double stipend)
    : Job(title, company), monthlyStipend(stipend) {
}

void Internship::display() const {
    cout << "Internship\n";
    cout << "Title: " << title << endl;
    cout << "Company: " << company << endl;
    cout << "Monthly Stipend: $" << monthlyStipend << endl;
}

double Internship::getPay() const {
    return monthlyStipend;
}
