#ifndef USER_H
#define USER_H

#include <string>
using std::string;

class User {
protected:
    string name;
    string email;

public:
    User(const string& name, const string& email);

    virtual void display() const = 0;
    virtual string getRole() const = 0;

    virtual ~User();
};

#endif
