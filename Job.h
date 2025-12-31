#ifndef JOB_H
#define JOB_H

#include <string>
#include <vector>
using namespace std;

#include "Application.h"

class Job {
protected:
    string title;
    string company;
    bool isOpen;
    vector<Application*> applications;

public:
    Job(const string& title, const string& company);

    void addApplication(Application* app);
    const vector<Application*>& getApplications() const;
    vector<Application*> getApplicationsByStatus(ApplicationStatus status) const;

    bool getIsOpen() const;
    void closeJob();
    void openJob();
    string getTitle() const;
    string getCompany() const;
	void hireApplicant(Application* hiredApp);

    virtual void display() const = 0;
    virtual double getMonthlyPay() const = 0;

    virtual ~Job();
};

#endif
