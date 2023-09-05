#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<int> s;
    int queries_count;
    cin >> queries_count;
    int query, parameter;
    for(int i=0; i<queries_count; i++)
    {
        cin >> query >> parameter;
        switch(query)
        {
            case 1:
                s.insert(parameter);
                break;
            case 2:
                s.erase(parameter);
                break;
            case 3:
                if(s.find(parameter)==s.end())
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
        }
    }
    return 0;
}

