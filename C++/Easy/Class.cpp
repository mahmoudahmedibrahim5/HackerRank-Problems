#include <iostream>
#include <sstream>
using namespace std;

class Student
{
    int age, standard;
    string first_name, last_name;
    
    public:
    void set_age(int Age)
    {age = Age;}
    int get_age(void)
    {return age;}  
    
    void set_standard(int Standard)
    {standard = Standard;}
    int get_standard(void)
    {return standard;}
    
    void set_first_name (string First_name)
    {first_name = First_name;}
    string get_first_name(void)
    {return first_name;}
    
    void set_last_name (string Last_name)
    {last_name = Last_name;}
    string get_last_name(void)
    {return last_name;}
    
    string to_string(void)
    {
        stringstream ss;
        ss << age << "," << first_name << "," << last_name << "," << standard;
        string s;
        ss >> s;
        return s;
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
