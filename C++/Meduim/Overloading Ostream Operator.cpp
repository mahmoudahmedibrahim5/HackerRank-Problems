#include <iostream>

using namespace std;

class Person
{
private:
    string firstName;
    string lastName;
public:
    Person(){}
    Person(string f, string l){
        firstName = f;
        lastName = l;
    }

    void setFirstName(string first){
        firstName = first;
    }
    string getFirstName(void){
        return firstName;
    }

    void setLastName(string last){
        lastName = last;
    }
    string getLastName(void){
        return lastName;
    }

};

ostream& operator<< (ostream& c, Person p)
{
    c << "first_name=" << p.getFirstName() << ",last_name=" << p.getLastName();
    return c;
}

int main()
{
    string firstName, lastName, event;
    cin >> firstName >> lastName >> event;

    Person p(firstName, lastName);

    cout << p << " " << event << endl;
    return 0;
}
