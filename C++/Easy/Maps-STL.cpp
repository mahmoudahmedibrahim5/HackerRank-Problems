#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    string studentName;
    int studentMark;
    map<string, int> m;
    map<string, int>::iterator returnValue;
    int number_of_queries;
    cin >> number_of_queries;  
    int queryNo;
    for(int i=0; i<number_of_queries; i++)
    {
        cin >> queryNo;
        cin >> studentName;
        switch (queryNo) 
        {
            case 1:
                cin >> studentMark;
                returnValue = m.find(studentName);
                if(returnValue == m.end())
                    m.insert(make_pair(studentName, studentMark));
                else
                    returnValue->second += studentMark; 
                break;
            case 2:
                m.erase(studentName);
                break;
            case 3:
                returnValue = m.find(studentName);
                if(returnValue != m.end())
                    cout << returnValue->second << endl;
                else
                    cout << 0 << endl;
                break;
        }
    }
    return 0;
}

