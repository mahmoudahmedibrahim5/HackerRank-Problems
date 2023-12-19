#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSub_set' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */
int k_global;
vector<int> _set;

int recursive(int index, vector<int> sub_set)
{
    if(index == (int)_set.size())
        return (int)sub_set.size();

    int choice1 = recursive(index + 1, sub_set);
    int choice2 = 0;

    bool choice2Validity = true;
    for(int i = 0; i < (int)sub_set.size(); i++){
        if( (sub_set[i] + _set[index])%k_global == 0){
            choice2Validity = false;
            break;
        }
    }
    if(choice2Validity)
    {
        sub_set.push_back(_set[index]);
        choice2 = recursive(index + 1, sub_set);
    }
    
    if(choice1 > choice2)
        return choice1;
    else
        return choice2;
}

int nonDivisibleSub_set(int k, vector<int> s) {
    vector<int> sub_set;
    for(int i = 0; i < (int)s.size(); i++){
        _set.push_back(s[i]);
    }
    k_global = k;
    return recursive(0, sub_set);;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSub_set(k, s);

    fout << result << "\n";

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
