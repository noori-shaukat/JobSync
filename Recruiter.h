#ifndef RECRUITER_H
#define RECRUITER_H

#include "User.h"
#include "Job.h"
#include "JobBoard.h"
#include "Application.h"

#include <vector>
#include <string>
using namespace std;

class Recruiter : public User {
private:
    string company;
    std::vector<Job*> postedJobs;

public:
    Recruiter(const string& name, const string& email, const string& company);

    void postJob(Job* job, JobBoard& board);

    void reviewApplications() const;
    void updateApplicationStatus(Application* app, ApplicationStatus status);

    void display() const override;
    string getRole() const override;

    string getCompany() const;

    const vector<Job*>& getPostedJobs() const { return postedJobs; }
    void reviewShortlisted() const;
	void displayPostedJobs() const;
	void displayApplicationsForJob(Job* job) const;

    void closeJob(Job* job);
    void openJob(Job* job);

};

#endif
