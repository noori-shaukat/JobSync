#include "User.h"

User::User(const string& name, const string& email)
    : name(name), email(email) {
}

string& User::getEmail() {
    return email;
}

string& User::getName() {
    return name;
}

User::~User() {
    // virtual destructor body (can be empty)
}
