#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, tmp;
    cin >> n;
    vector <int> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        v.at(i) = tmp;
    }
    int index;
    cin >> index;
    v.erase(v.begin()+index-1);
    int start, end;
    cin >> start >> end;
    v.erase(v.begin()+start-1, v.begin()+end-1);
    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    return 0;
}
