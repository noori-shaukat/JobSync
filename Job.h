#ifndef JOB_H
#define JOB_H

#include <string>
#include <vector>
using namespace std;

class Job {
protected:
    string title;
    string company;
    std::vector<Application*> applications;

public:
    Job(const string& title, const string& company);

    void addApplication(Application* app);
    const std::vector<Application*>& getApplications() const;

    virtual void display() const = 0;
    virtual double getPay() const = 0;

    virtual ~Job();
};

#endif
