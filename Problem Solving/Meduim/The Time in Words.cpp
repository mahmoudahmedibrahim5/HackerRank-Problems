#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    string result;

    string numbers[30] = {"one", "two", "three", "four", "five",
                          "six", "seven", "eight", "nine", "ten",
                          "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                          "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
                          "twenty one", "twenty two", "twenty three", "twenty four", "twenty five",
                          "twenty six", "twenty seven", "twenty eight", "twenty nine", "thirty"
                            };

    if(m == 0){
        result = numbers[h - 1];
        result += " o' clock";
    }
    else if(m == 15){
        result = "quarter past ";
        result += numbers[h - 1];
    }
    else if(m == 30){
        result = "half past ";
        result += numbers[h - 1];
    }
    else if(m == 45){
        result = "quarter to ";
        result += numbers[h];
    }
    else if(m < 30){
        result = numbers[m - 1];
        if(m == 1)
            result += " minute past ";
        else
            result += " minutes past ";
        result += numbers[h - 1];
    }
    else{
        result = numbers[(60 -m) - 1];
        result += " minutes to ";
        result += numbers[h];
    }       

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
