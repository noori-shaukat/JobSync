#ifndef APPLICANT_H
#define APPLICANT_H

#include "User.h"
#include <string>
#include <vector>

class Job;          // forward declaration
class Application;  // forward declaration

using std::string;

class Applicant : public User {
private:
    string resume;
    std::vector<Application*> applications;

public:
    Applicant(const string& name, const string& email, const string& resume);

    void apply(Job* job);
    void displayApplications() const;

    void display() const override;
    string getRole() const override;

    ~Applicant();
};

#endif
