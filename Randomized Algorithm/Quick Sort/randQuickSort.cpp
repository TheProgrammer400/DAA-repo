#include<iostream>
#include<vector>
#include<algorithm> // for swap()
#include<cstdlib>   // for rand()
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(vector<int> &arr, int low, int high){
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pivotIndex = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int> &arr){
    for(int num : arr){
        cout << num << " ";
    }

    cout << endl;
}

int main() {
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};

    cout << "Original array: ";
    printArray(arr);

    randomizedQuickSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    
    printArray(arr);
    return 0;
}
