#include "Profile.h"
#include <iostream>

using namespace std;

Profile::Profile() {
    // default empty profile
}

void Profile::setEducation(const string& education) {
    this->education = education;
}

void Profile::setExperience(const string& experience) {
    this->experience = experience;
}

void Profile::addSkill(const string& skill) {
    skills.push_back(skill);
}

void Profile::setResumePath(const string& path) {
    resumePath = path;
}

void Profile::setCoverLetterTemplate(const string& text) {
    coverLetterTemplate = text;
}

void Profile::addPortfolioLink(const string& link) {
    portfolioLinks.push_back(link);
}

void Profile::display() const {
    cout << "Education: " << education << endl;
    cout << "Experience: " << experience << endl;

    cout << "Skills: ";
    for (const auto& skill : skills)
        cout << skill << ", ";
    cout << endl;

    cout << "Resume: " << resumePath << endl;
    cout << "Cover Letter Template: " << coverLetterTemplate << endl;

    cout << "Portfolio Links:" << endl;
    for (const auto& link : portfolioLinks)
        cout << "- " << link << endl;
}
