#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sherlockAndMinimax' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER p
 *  3. INTEGER q
 */

int sherlockAndMinimax(vector<int> arr, int p, int q) {
    int arrSize = (int) arr.size();
    int max = 0, index = 0, minimum;
    sort(arr.begin(), arr.end());
    
    int minIndex = 1;
    for(int i = p; i <= q; i++)
    {
        minimum = abs(arr.at(0)-i);
        for(int j = minIndex; j < arrSize; j++)
        {
            if(abs(arr.at(j)-i) < minimum){
                minimum = abs(arr.at(j)-i);
                minIndex = j;
            }
            if(minimum == 0 || arr.at(j) > i)
                break;
        }
        if(minimum > max){
            max = minimum;
            index = i;
        }
    }
    return index;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int p = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    int result = sherlockAndMinimax(arr, p, q);

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
