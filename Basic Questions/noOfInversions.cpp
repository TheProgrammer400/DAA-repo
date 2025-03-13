#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high, int *count){
    int left = low;
    int right = mid+1;

    vector<int> temp;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) { // <= is important for stability
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
            *count = *count + (mid - left + 1); // Corrected inversion count
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low]; // Copy back to original array
    }
}

void mergeSort(vector<int> &arr, int low, int high, int *count){
    if (low == high){
        return ;
    }

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid+1, high, count);
    merge(arr, low, mid, high, count);
}

int main(){
    vector<int> arr = {2,3,8,6,1};
    int count = 0;
    mergeSort(arr, 0, 4, &count);
    cout<<count;

    return 0;
}