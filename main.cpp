#include <iostream>
#include <vector>

#include "Applicant.h"
#include "FullTimeJob.h"
#include "PartTimeJob.h"
#include "Internship.h"
#include "JobBoard.h"
#include "Application.h"
#include "Recruiter.h"

using namespace std;

int main() {
    JobBoard board;
    Recruiter recruiter("Ali", "ali@company.com", "Google");

    recruiter.postJob(new FullTimeJob("Software Engineer", "Google", 120000), board);
    recruiter.postJob(new Internship("Backend Intern", "Google", 1500), board);

    Applicant applicant("Noori", "noori@email.com");
    applicant.apply(board.getJobs()[0]);
    applicant.apply(board.getJobs()[1]);

    recruiter.reviewApplications();

    recruiter.updateApplicationStatus(
        board.getJobs()[0]->getApplications()[0],
        ApplicationStatus::Shortlisted
    );

    applicant.displayApplications();

    cout << "Program finished successfully.\n";
    return 0;
}
