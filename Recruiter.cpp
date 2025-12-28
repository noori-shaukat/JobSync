#include "Recruiter.h"
#include <iostream>
using std::cout;
using std::endl;

Recruiter::Recruiter(const string& name, const string& email, const string& company)
    : User(name, email), company(company) {
}

void Recruiter::display() const {
    cout << "Recruiter Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Company: " << company << endl;
}

string Recruiter::getRole() const {
    return "Recruiter";
}
