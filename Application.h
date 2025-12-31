#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

enum class ApplicationStatus {
    Submitted,
    Viewed,
    Shortlisted,
    Rejected,
    Hired
};

class Applicant;
class Job;

class Application {
private:
    Applicant* applicant;
    Job* job;
    ApplicationStatus status;

public:
    Application(Applicant* applicant, Job* job);
    
    Applicant* getApplicant() const;
    Job* getJob() const;

    void display() const;
    void displayForRecruiter() const;
    void displayForApplicant() const;

    void setStatus(ApplicationStatus newStatus);
    ApplicationStatus getStatus() const;
    std::string statusToString(ApplicationStatus status) const;

};

#endif
