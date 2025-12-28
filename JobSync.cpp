#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;
    string email;

public:
    User(string name, string email) {
        this->name = name;
        this->email = email;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }

    virtual ~User() {}
};

int main() {
    User u("Noori", "noori@email.com");
    u.display();
}
