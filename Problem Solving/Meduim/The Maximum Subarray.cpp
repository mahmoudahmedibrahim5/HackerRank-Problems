#include <iostream>
#include <vector>
#include <algorithm>

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
    mem[0] = new int[1];
    mem[0][0] = sum;
    result[0] = sum;
    for(int i = 1; i < n - 1; i++)
    {
        mem[i] = new int[i + 1];
        for(int j = 0; j <= i; j++)
        {
            if(i == j)
            {
                mem[i][j] = mem[i-1][j-1] - arr[i-1];
            }
            else
            {
                mem[i][j] = mem[i-1][j] - arr[n - i + j];
            }
            if(mem[i][j] > result[0])
                result[0] = mem[i][j];
        }
        delete [] mem[i - 1];
    }
    if(largest > result[0])
        result[0] = largest;
    delete [] mem[n - 1];
    delete [] mem;
    return result;
    // vector<int> result(2);
    // int n = (int)arr.size();    // The length of the array
    // int** mem = new int*[n];    // Table for the results of subarrays
    
    // int sum = 0;                // sum of all elements in the array
    // int largest = arr[0];       // largest element in the array
    // for(int i = 0; i < n; i++){
    //     sum += arr[i];
    //     if(arr[i] > 0){
    //         result[1] += arr[i];
    //     }
    //     else{
    //         /* In case all elements of the array are negative numbers */
    //         if(arr[i] > largest)
    //             largest = arr[i];
    //     }
    // }
    // /* In case all elements of the array are negative numbers */
    // if(result[1] == 0){
    //     result[1] = largest;
    //     result[0] = largest;
    //     return result;
    // }else if(result[1] == sum){
    //     result[0] = sum;
    //     return result;
    // }

    // /* Calculate the values of the table and find the maximum one */
    // mem[0] = new int[1];
    // mem[0][0] = sum;
    // result[0] = sum;
    // for(int i = 1; i < n; i++)
    // {
    //     mem[i] = new int[i + 1];
    //     for(int j = 0; j <= i; j++)
    //     {
    //         if(i == j)
    //         {
    //             mem[i][j] = mem[i-1][j-1] - arr[i-1];
    //         }
    //         else
    //         {
    //             mem[i][j] = mem[i-1][j] - arr[n - i + j];
    //         }
    //         if(mem[i][j] > result[0])
    //             result[0] = mem[i][j];
    //     }
    //     delete [] mem[i - 1];
    // }
    // delete [] mem[n - 1];
    // delete [] mem;
    // return result;
}
// vector<int> maxSubarray(vector<int> arr) {
//     vector<int> result(2);
//     int n = (int)arr.size();    // The length of the array
//     int** mem = new int*[n];    // Table for the results of subarrays
    
//     result[0] = 0;
//     if(arr[0] > 0)
//         result[1] = arr[0];
//     else
//         result[1] = 0;
    
//     /* Calculate the values of the table and find the maximum one */
//     mem[0] = new int[1];
//     mem[0][0] = 0;
    
//     int sum = arr[0];                // sum of all elements in the array
//     int largest = arr[0];           // largest element in the array
//     for(int i = 1; i < n; i++)
//     {
//         sum += arr[i];
//         if(arr[i] > 0){
//             result[1] += arr[i];
//         }
//         else{
//             if(arr[i] > largest)
//                 largest = arr[i];
//         }
//         mem[i] = new int[i + 1];
//         for(int j = 0; j <= i; j++)
//         {
//             if(i == j)
//             {
//                 mem[i][j] = mem[i-1][j-1] - arr[i-1];
//             }
//             else
//             {
//                 mem[i][j] = mem[i-1][j] - arr[n - i + j];
//             }
//             if(mem[i][j] > result[0])
//                 result[0] = mem[i][j];
//         }
//         delete [] mem[i - 1];
//     }
//     delete [] mem[n - 1];
//     delete [] mem;
    
//     result[0] += sum;
    
//     /* In case all elements of the array are negative numbers */
//     if(result[1] == 0){
//         result[1] = largest;
//         result[0] = largest;
//     }
    
//     return result;
// }
int main()
{
    //ofstream cout(getenv("OUTPUT_PATH"));

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
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    //cout.close();

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
