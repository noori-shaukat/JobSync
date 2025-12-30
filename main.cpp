#include <iostream>
#include "Applicant.h"
#include "Recruiter.h"
#include "FullTimeJob.h"
#include "PartTimeJob.h"
#include "Internship.h"

using namespace std;

int main() {
    Applicant* a1 = new Applicant("Noor", "noor@email.com", "CS Student");
    Applicant* a2 = new Applicant("Ali", "ali@email.com", "SE Student");

    Job* j1 = new FullTimeJob("Software Engineer", "Google", 120000);
    Job* j2 = new Internship("Intern", "Microsoft", 2500);

    a1->apply(j1);
    a1->apply(j2);
    a2->apply(j2);

    cout << "Applications by Noori:\n";
    a1->displayApplications();

    cout << "\nApplications by Ali:\n";
    a2->displayApplications();

    delete a1;
    delete a2;
    delete j1;
    delete j2;

    return 0;
}
