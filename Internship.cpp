#include "Internship.h"
#include <iostream>
using namespace std;

Internship::Internship(const string& title, const string& company, double stipend)
    : Job(title, company), monthlyStipend(stipend) {
}

void Internship::display() const {
    cout << "Internship\n";
    cout << "Title: " << title << endl;
    cout << "Company: " << company << endl;
    cout << "Monthly Stipend: $" << monthlyStipend << endl;
    cout << "Status: " << (isOpen ? "Open" : "Closed") << endl;
    cout << endl;
}

double Internship::getMonthlyPay() const {
    return monthlyStipend;
}
