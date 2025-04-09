#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class SubArray{
    public:
        int left;
        int right;
        int sum;
};

SubArray crossingSum(vector<int> &arr, int low, int mid, int high){
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;

    int maxLeft = 0;
    int maxRight = 0;

    for(int i=mid; i>=low; i--){
        sum = sum + arr[i];

        if (sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;

    for(int i=mid+1; i<=high; i++){
        sum = sum + arr[i];

        if (sum > rightSum){
            rightSum = sum;
            maxRight = i;
        }
    }

    return {maxLeft, maxRight, leftSum + rightSum};
}

SubArray maxSubArraySum(vector<int> &arr, int low, int high){
    if (low == high){
        return {low, low, arr[low]};
    }

    int mid = low + (high - low) / 2;

    SubArray leftArr = maxSubArraySum(arr, low, mid);
    SubArray rightArr = maxSubArraySum(arr, mid+1, high);
    SubArray crossingArr = crossingSum(arr, low, mid, high);

    if (leftArr.sum >= rightArr.sum && leftArr.sum >= crossingArr.sum){
        return leftArr;
    } else if (rightArr.sum >= leftArr.sum && rightArr.sum >= crossingArr.sum){
        return rightArr;
    } else {
        return crossingArr;
    }
}

void printResult(SubArray result, vector<int> arr){
    cout<<"Max Sum: "<<result.sum<<endl;

    cout<<"Max sub array: ";

    for(int i=result.left; i<=result.right; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    SubArray result = maxSubArraySum(arr, 0, arr.size()-1);
    printResult(result, arr);

    return 0;
}