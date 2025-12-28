#ifndef APPLICANT_H
#define APPLICANT_H

#include "User.h"
#include <string>
using std::string;

class Applicant : public User {
private:
    string resume;

public:
    Applicant(const string& name, const string& email, const string& resume);

    void display() const override;
    string getRole() const override;
};

#endif
