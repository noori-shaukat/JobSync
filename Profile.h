#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <vector>

using namespace std;

class Profile {
private:
    string education;
    string experience;
    vector<string> skills;
    string resumePath;
    string coverLetterTemplate;
    vector<string> portfolioLinks;

public:
    // constructors
    Profile();

    // setters
    void setEducation(const string& education);
    void setExperience(const string& experience);
    void addSkill(const string& skill);
    void setResumePath(const string& path);
    void setCoverLetterTemplate(const string& text);
    void addPortfolioLink(const string& link);

    // display
    void display() const;
};

#endif
