#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
typedef struct Workshop{
    int startTime;
    int duration;
    int endTime;
}Workshop;

typedef struct{
    int n;
    Workshop* arr;
    int smallest;
}Available_Workshops;

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops* result = new Available_Workshops;
    result->n = n;
    result->arr = new Workshop[n];
    result->smallest = start_time[0] + duration[0];
    
    for(int i = 0; i < n; i++)
    {
        result->arr[i].startTime = start_time[i];
        result->arr[i].duration = duration[i];
        result->arr[i].endTime = start_time[i] + duration[i];
        if(result->arr[i].endTime < result->smallest)
            result->smallest = result->arr[i].endTime;
    }
    return result;    
}
// vector<vector<int>> memoize;
// int recursive(int endTime, Available_Workshops* ptr)
// {
//     for(int i = 0; i < (int)memoize.size(); i++){
//         if(memoize.at(i).at(0) == endTime)
//             return memoize.at(i).at(1) + 1;
//     }
    
//     int result = 0;
//     int test;
//     for(int i = 0; i < ptr->n; i++){
//         if(ptr->arr[i].startTime >= endTime){
//             test = recursive(ptr->arr[i].endTime, ptr);
//             if(test > result)
//                 result = test;
//         }
//     }
//     vector<int> element;
//     element.push_back(endTime);
//     element.push_back(result);
//     return result + 1;
// }
int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    Workshop tmp;
    for(int i = 0; i < ptr->n; i++)
    {
        for(int j = 0; j < ptr->n - 1 - i; j++)
        {
            if(ptr->arr[j].endTime > ptr->arr[j+1].endTime)    
            {
                tmp = ptr->arr[j];
                ptr->arr[j] = ptr->arr[j+1];
                ptr->arr[j+1] = tmp;
            }
        }
    }
    
    int result;
    int max = 0;
    int end;
    
    for(int i = 0; i < ptr->n; i++)
    {
        if(ptr->smallest <= ptr->arr[i].startTime)
            continue;
        result = 1;
        end = ptr->arr[i].endTime;
        for (int j = i + 1; j < ptr->n; j++)
        {
            if(ptr->arr[j].startTime >= end){
                result++; 
                end = ptr->arr[j].endTime;
            }
        }
        if(result > max)
            max = result;
    }
    return max;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
