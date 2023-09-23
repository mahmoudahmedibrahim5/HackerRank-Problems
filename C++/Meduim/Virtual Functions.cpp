#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
protected:
    string name;
    int age;    
public:
    virtual void putdata(void) = 0;
    virtual void getdata(void) = 0;     
};

int professorID = 1;
int studentID = 1;

class Professor :public Person{
private:
    int publications;
    int cur_id;
public:
    Professor(void){
        cur_id = professorID++;
    }
    void putdata(void){
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
    void getdata(void){
        cin >> name >> age >> publications;
    }
};

class Student :public Person{
private:
    int marks[6];
    int cur_id;
public:
    Student(void){
        cur_id = studentID++;
    }
    void putdata(void){
        int sum = 0;
        for(int i = 0; i < 6; i++){
            sum += marks[i];
        }
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
    void getdata(void){
        cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
