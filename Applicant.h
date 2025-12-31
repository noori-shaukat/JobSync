#ifndef APPLICANT_H
#define APPLICANT_H

#include "User.h"
#include "Profile.h"

#include <string>
#include <vector>

class Job;
class Application;

using std::string;

class Applicant : public User {
private:
    Profile profile;
    std::vector<Application*> applications;

public:
    Applicant(const string& name, const string& email);

    bool apply(Job* job);
    void displayApplications() const;
    
    const std::vector<Application*>& getApplications() const;

    Profile& getProfile();

    void display() const override;
    string getRole() const override;

    ~Applicant();
};

#endif
