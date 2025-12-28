#ifndef RECRUITER_H
#define RECRUITER_H

#include "User.h"
#include <string>
using std::string;

class Recruiter : public User {
private:
    string company;

public:
    Recruiter(const string& name, const string& email, const string& company);

    void display() const override;
    string getRole() const override;
};

#endif
