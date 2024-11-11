#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define BIG_NUM     0x80000000U

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int n, s, p, q;
    cin >> n >> s >> p >> q;
    
    unsigned int a1, a2;
    unsigned int result = 1;
    
    a1 = s % BIG_NUM;
    for(int i = 1; i < n; i++){
        a2 = (a1 * p + q) % BIG_NUM;
        if(a2 == a1 || a2 == s)
            break;
        result++;
        a1 = a2;
    }
    
    cout << result << endl;
    return 0;
}
