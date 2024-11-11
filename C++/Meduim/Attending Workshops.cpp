#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop{
    int startTime;
    int duration;
    
    bool operator<(const Workshop& other) const{
        if((startTime + duration) == (other.startTime + other.duration))
            return startTime > other.startTime;
        else
            return (startTime + duration) < (other.startTime + other.duration);
    }
};

struct Available_Workshops{
    int n;
    Workshop* arr;    
};

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int startTime[], int duration[], int n)
{
    Available_Workshops* result = new Available_Workshops;
    result->arr = new Workshop[n];
    
    vector<Workshop> arr(n);
    for(int i = 0; i < n; i++){
        arr[i].startTime = startTime[i];
        arr[i].duration = duration[i];
    }
    sort(arr.begin(), arr.end());
    
    int endTime;
    endTime = arr[0].startTime + arr[0].duration;
    result->n = 1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].startTime >= endTime){
            endTime = arr[i].startTime + arr[i].duration;
            result->arr[result->n - 1] = arr[i];
            result->n++;
        }
    }
    
    return result;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    return ptr->n;
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
