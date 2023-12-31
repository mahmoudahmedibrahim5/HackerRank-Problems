#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> takeInput(int n);
vector<int> findMaximums(vector<int> arr, int k);
void printVector(vector<int> arr);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        vector<int> results;

        arr = takeInput(n);
        results = findMaximums(arr, k);
        printVector(results);

        cout << endl;
    }

    return 0;
}

vector<int> takeInput(int n)
{
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}

vector<int> findMaximums(vector<int> arr, int k)
{
    int n = (int)arr.size();
    deque<int> subArray;
    vector<int> results(n-k+1);

    results[0] = 0;
    for(int i = 0; i < k; i++){
        subArray.push_back(arr[i]);
        if(subArray[i] > results[0])
            results[0] = subArray[i];
    }

    /* Calculate The max of the rest sub arrays */
    for(int i = 1; i < n-k+1; i++)
    {
        int tmp = subArray[0];
        subArray.pop_front();
        subArray.push_back(arr[k + i - 1]);
        if(results[i - 1] < arr[k + i - 1])
            results[i] = arr[k + i - 1];
        else if(results[i - 1] != tmp){
                results[i] = results[i - 1];
        }
        else{
            results[i] = 0;
            for(int j = 0; j < k; j++){
                if(subArray[j] > results[i])
                    results[i] = subArray[j];
            }
        }
    }
    return results;
}

void printVector(vector<int> arr)
{
    for(int i = 0; i < (int)arr.size(); i++)
        cout << arr[i] << " ";
}
