#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int equal(vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    vector<int> copy1;
    vector<int> copy2;
    vector<int> copy3;
    for(int i = 0; i < (int)arr.size(); i++){
        copy1.push_back(arr[i]);
        copy2.push_back(arr[i]);
        copy3.push_back(arr[i]);
    }
    
    /* Criteria 1 */
    unsigned long long incr = 0;
    unsigned long long result1 = 0;
    int diff;
    for(int i = 0; i < (int)arr.size() - 1; i++)   
    {
        arr[i + 1] += incr;
        if(arr[i] != arr[i + 1])
        {
            diff = arr[i + 1] - arr[i];
            incr += diff;
            result1 += (diff / 5);
            diff %= 5;
            if(diff == 4)
            {
                incr -= 4;
                
                // Make diff = 5
                incr++;
                arr[i + 1]++;
                result1++;
                
                incr += 5;
                result1++;
            }
            else
            {
                result1 += (diff / 2);
                diff %= 2;
                result1 += (diff / 1);
                diff %= 1;
            }
        }
    }   
    
    /* Criteria 2 */
    unsigned long long result2 = 0;
    incr = 0;
    for(int i = 0; i < (int)copy1.size() - 1; i++)   
    {
        copy1[i + 1] += incr;
        if(copy1[i] != copy1[i + 1])
        {
            diff = copy1[i + 1] - copy1[i];
            incr += diff;
            result2 += (diff / 5);
            diff %= 5;
            result2 += (diff / 2);
            diff %= 2;
            result2 += (diff / 1);
            diff %= 1;
        }
    }
    
    /* Criteria 3 */
    unsigned long long result3 = 0;
    incr = 0;
    for(int i = 0; i < (int)copy2.size() - 1; i++)   
    {
        copy2[i + 1] += incr;
        if(copy2[i] != copy2[i + 1])
        {
            diff = copy2[i + 1] - copy2[i];
            incr += diff;
            result3 += (diff / 5);
            diff %= 5;
            if(diff == 3)
            {
                incr -= 3;
                
                // Make diff = 5
                incr += 2;
                copy2[i + 1] += 2;
                result3++;
                
                incr += 5;
                result3++;
            }
            else
            {
                result3 += (diff / 2);
                diff %= 2;
                result3 += (diff / 1);
                diff %= 1;
            }
        }
    }   
    
    /* Criteria 4 */
    unsigned long long result4 = 0;
    incr = 0;
    for(int i = 0; i < (int)copy3.size() - 1; i++)   
    {
        copy3[i + 1] += incr;
        if(copy3[i] != copy3[i + 1])
        {
            diff = copy3[i + 1] - copy3[i];
            incr += diff;
            result4 += (diff / 5);
            diff %= 5;
            if(diff == 4)
            {
                incr -= 4;
                
                // Make diff = 5
                incr++;
                copy3[i + 1]++;
                result4++;
                
                incr += 5;
                result4++;
            }
            else if(diff == 3)
            {
                incr -= 3;
                
                // Make diff = 5
                incr += 2;
                copy3[i + 1] += 2;
                result4++;
                
                incr += 5;
                result4++;
            }
            else
            {
                result4 += (diff / 2);
                diff %= 2;
                result4 += (diff / 1);
                diff %= 1;
            }
        }
    }   
    unsigned long long result = result1;
    if(result2 < result)
        result = result2;
    if(result3 < result)
        result = result3;
    if(result4 < result)
        result = result4;
        
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

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

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
