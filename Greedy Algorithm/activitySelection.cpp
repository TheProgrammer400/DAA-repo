#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Activity{
    public:
        int start;
        int finish;

        Activity(int start, int finish){
            this->start = start;
            this->finish = finish;
        }
};

bool comparator(Activity a1, Activity a2){
    return a1.finish < a2.finish;
}

void activitySelection(vector<Activity> &arr){
    sort(arr.begin(), arr.end(), comparator); // sorting the activity who finishes first

    cout<<"Selected activities: "<<endl;
    int lastFinish = arr[0].finish;

    cout<<"("<<arr[0].start<<", "<<arr[0].finish<<")"<<endl;

    for(int i=1; i<arr.size(); i++){
        if (arr[i].start >= lastFinish){ // checking if the current activity doesn't overlap
            cout<<"("<<arr[i].start<<", "<<arr[i].finish<<")"<<endl;
            lastFinish = arr[i].finish;
        }
    }
}

int main(){
    vector<Activity> activities = {
        Activity(1, 3), Activity(2, 5), Activity(4, 6),
        Activity(6, 8), Activity(5, 7), Activity(8, 9)
    };

    activitySelection(activities);
    return 0;
}