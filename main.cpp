#include <vector>
#include <iostream>

#include "Applicant.h"
#include "Recruiter.h"
#include "FullTimeJob.h"
#include "PartTimeJob.h"
#include "Internship.h"

using namespace std;

int main() {
    vector<User*> users;

    users.push_back(new Applicant("Noor", "noor@email.com", "CS Student"));
    users.push_back(new Recruiter("Ali", "ali@email.com", "Google"));

    for (User* u : users) {
        u->display();
        cout << "Role: " << u->getRole() << endl << endl;
    }

    for (User* u : users)
        delete u;

    vector<Job*> jobs;

    jobs.push_back(new FullTimeJob("SWE", "Google", 120000));
    jobs.push_back(new PartTimeJob("Lab Assistant", "Uni", 20, 15));
    jobs.push_back(new Internship("Intern", "Microsoft", 2500));

    for (Job* j : jobs) {
        j->display();
        cout << "Pay: $" << j->getPay() << endl << endl;
    }


    return 0;
}
