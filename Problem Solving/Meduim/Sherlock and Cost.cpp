#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY B as parameter.
 */

long long int cost(vector<int> B) {
    long long int result = 0;
    int previous;
    long long int a = 0;
    long long int b = 0;
    
    long long int copyA;
    for(int i = 1; i < B.size(); i++)
    {
        previous = B.at(i - 1);
        copyA = a;
        if( abs(B.at(i) - previous) + a > abs(B.at(i) - 1) + b ){
            a = abs(B.at(i) - previous) + a;
        }
        else{
            a = abs(B.at(i) - 1) + b;
        }
        
        if( abs(1 - previous) + copyA > abs(1 - 1) + b ){
            b = abs(1 - previous) + copyA;
        }
        else{
            b = abs(1 - 1) + b;
        }
        //printf("at i = %d, prev = %d, a = %d, b = %d\n", i, previous, a, b);
    }
    if(a > b)
        result = a;
    else
        result = b;
        
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split(rtrim(B_temp_temp));

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        long long int result = cost(B);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
