#ifndef JOB_H
#define JOB_H

#include <string>
using std::string;

class Job {
protected:
    string title;
    string company;

public:
    Job(const string& title, const string& company);

    virtual void display() const = 0;
    virtual double getPay() const = 0;

    virtual ~Job();
};

#endif
