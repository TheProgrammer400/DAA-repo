#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2){
    // comparator function that sort the vector based on the weight of the pair in desencding order
    float weight1, weight2;

    weight1 = (float) p1.first / p1.second;
    weight2 = (float) p2.first / p2.second;

    return weight1 > weight2;
}

int main(){
    int n;

    cin>>n;
    vector<pair<int, int>> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }

    sort(arr.begin(), arr.end(), comparator);

    for(int i=0; i<n; i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }

    int weight = 90;
    float sum = 0;

    for(int i=0; i<n; i++){
        if (arr[i].second < weight){
            weight = weight - arr[i].second;
            sum = sum + arr[i].first;
        } else {
            float fraction = (float) arr[i].first * weight / arr[i].second;
            sum = sum + fraction;
        }
    }

    cout<<"Max: "<<sum<<endl;
    return 0;
}