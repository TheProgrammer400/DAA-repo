#include<iostream>
#include<vector>
using namespace std;

void findSubsets(vector<int> &arr, int index, vector<int> &current, int sum, int target) {
    if(sum == target) {
        cout << "Subset found: ";

        for(int num : current) {
            cout << num << " ";
        }
        
        cout << endl;
        return;
    }
    
    if(index >= arr.size() || sum > target) {
        return;
    }
    
    // Include the current element
    current.push_back(arr[index]);
    findSubsets(arr, index + 1, current, sum + arr[index], target);
    current.pop_back();
    
    // Exclude the current element
    findSubsets(arr, index + 1, current, sum, target);
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the target sum: ";
    cin >> target;
    
    vector<int> current;
    findSubsets(arr, 0, current, 0, target);
    
    return 0;
}
