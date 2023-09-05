#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size, tmp, q, n;
    vector <int> :: iterator index;
    cin >> size;
    vector <int> v(size);
    for(int i=0; i<size; i++)
    {
        cin >> tmp;
        v.at(i) = tmp;
    }
    cin >> q;
    int i, j;
    for(i=0; i<q; i++)
    {
        cin >> n;
        index = lower_bound(v.begin(), v.end(), n);
        if(v.at(index-v.begin())==n)
            cout << "Yes " << (index-v.begin()+1) << endl;
        else
            cout << "No " << (index-v.begin()+1) << endl;
    }
    return 0;
}
