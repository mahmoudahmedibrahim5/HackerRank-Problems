#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

#define SORTED      0
#define SWAP        1
#define REVERSE     2
#define UNSORTED    3

void almostSorted(vector<int> arr) {
    int result = SORTED;
    int start, end = 0;
    int n = (int)arr.size();
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            if(result == SORTED)
            {
                if(i >= n - 2){
                    result = SWAP;
                    start = i;
                    end = i + 1;
                }
                else{
                    if(arr[i + 1] > arr[i + 2])
                        result = REVERSE;
                    else
                        result = SWAP;
                    start = i;
                    if(result == SWAP && arr[i] < arr[i + 2])
                        end = i + 1;
                }
                
            }
            else if(result == SWAP)
            {
                if(end == 0 && (arr[start] > arr[i]) && (arr[i + 1] < arr[start + 1])){
                    end = i + 1;
                }
                else{
                    result = UNSORTED;
                    break;
                }
            }
            else if(result == REVERSE && end != 0)
            {
                result = UNSORTED;
                break;
            }
        }
        else if(result == REVERSE && end == 0)
        {
            end = i;
        }
    }
    if(result == SWAP && end == 0)
        result = UNSORTED;
    if(result == REVERSE && end == 0)
        end = n - 1;
    if(start != 0 && (arr[end] < arr[start - 1]))
        result = UNSORTED;
    if(end != n-1 && (arr[start] > arr[end + 1]))
        result = UNSORTED;

    if(result == SORTED)
        cout << "yes" << endl;
    else if(result == SWAP)
        cout << "yes" << endl<< "swap " << start + 1 << " " << end + 1 << endl;
    else if(result == REVERSE)
        cout << "yes" << endl<< "reverse " << start + 1 << " " << end + 1 << endl;
    else if(result == UNSORTED)
        cout << "no" << endl;
}

int main()
{
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

    almostSorted(arr);

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
