# JobSync

## Project Overview

**JobSync** is a console-based C++ application that simulates a realistic job application platform. It allows applicants to manage their profiles and job applications, while recruiters can post jobs, review applications, and manage hiring workflows. A centralized JobBoard provides sorting and filtering of available jobs.

The project demonstrates object-oriented programming principles including classes, inheritance, polymorphism, encapsulation, dynamic memory management, and functional programming using lambda functions for sorting and filtering.

---

## Motivation

As final-year students, managing multiple applications across different platforms can be overwhelming. We often face difficulties keeping track of applications, and many times, we get ghosted by recruiters. JobSync was developed to simulate this process in a controlled environment, helping students practice object-oriented programming in C++ while experiencing a simplified, realistic recruitment workflow.

---

## Features

### Applicant
- Create and manage detailed profiles (education, experience, skills, resume, portfolio, cover letter templates).  
- View all open jobs on the JobBoard.  
- Apply to multiple jobs while avoiding duplicates and closed positions.  
- Track application status (Submitted, Viewed, Shortlisted, Rejected, Hired).  
- Filter applications by status.  

### Recruiter
- Post new jobs: Full-Time, Part-Time, and Internship.  
- View posted jobs with indexed menus.  
- Review applications for specific jobs with indexed lists of applicants.  
- Update application status: shortlist, hire, or reject. Hiring automatically closes the job and rejects other candidates.  
- Open and close jobs manually.  
- Review shortlisted applicants.  

### JobBoard
- Stores all jobs centrally.  
- Display jobs sorted by title, company, or pay.  
- Filter jobs by status, keyword, or company.  

---

## System Design

- **Users:** `Applicant` and `Recruiter` inherit from `User`.  
- **Jobs:** `FullTimeJob`, `PartTimeJob`, and `Internship` inherit from `Job`.  
- **Applications:** Link applicants to jobs and track status.  
- **JobBoard:** Central repository of all jobs, supporting sorting and filtering.  

Relationships:
- Applicants create `Application` objects referencing `Job`.  
- Jobs maintain lists of applications for recruiter review.  
- Recruiters own jobs they post.  
- JobBoard stores references to all jobs.  

Memory Management:
- Jobs delete their applications upon destruction.  
- Applicants and recruiters are deleted at program exit to avoid leaks.  

---

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/noori-shaukat/JobSync.git
   ```
2. Open the project in your preferred C++ IDE (Visual Studio recommended).
3. Build and run the executable.
4. The console application allows users to log in as an applicant or recruiter and interact with the system.

---

## Example Workflow

1. Applicants view open jobs and apply to multiple positions.
2. Recruiters post jobs, review applications, and hire candidates.
3. Hired candidates’ statuses are updated automatically, and the job closes.
4. Applicants can view all applications with real-time status updates.

