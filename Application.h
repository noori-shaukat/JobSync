#ifndef APPLICATION_H
#define APPLICATION_H

class Applicant;   // forward declaration
class Job;         // forward declaration

class Application {
private:
    Applicant* applicant;
    Job* job;

public:
    Application(Applicant* applicant, Job* job);
    void display() const;
};

#endif
