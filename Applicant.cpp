#include "Applicant.h"
#include <iostream>
using std::cout;
using std::endl;

Applicant::Applicant(const string& name, const string& email, const string& resume)
    : User(name, email), resume(resume) {
}

void Applicant::display() const {
    cout << "Applicant Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Resume: " << resume << endl;
}

string Applicant::getRole() const {
    return "Applicant";
}
