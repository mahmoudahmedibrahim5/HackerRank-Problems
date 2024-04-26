#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxSubarray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> maxSubarray(vector<int> arr) {
    vector<int> result(2);
    int n = (int)arr.size();    // The length of the array
    int** mem = new int*[n];    // Table for the results of subarrays
    
    int sum = 0;                // sum of all elements in the array
    int largest = arr[0];       // largest element in the array
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(arr[i] > 0){
            result[1] += arr[i];
        }
        if(arr[i] > largest){
                largest = arr[i];
                cout << "Largest = " << largest << endl;
            }
    }
    /* In case all elements of the array are negative numbers */
    if(result[1] == 0){
        result[1] = largest;
        result[0] = largest;
        return result;
    }else if(result[1] == sum){
        result[0] = sum;
        return result;
    }

    /* Calculate the values of the table and find the maximum one */
    int subArraySum = 0;
    result[0] = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0){
            if(abs(arr[i]) > subArraySum)
                subArraySum = 0;
            else{
                subArraySum += arr[i];
            }
        }
        else{
            subArraySum += arr[i];
        }
        if(subArraySum > result[0])
            result[0] = subArraySum;
    }
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

        vector<int> result = maxSubarray(arr);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
