#include <iostream>
#include <vector>
using namespace std;

// kadane algorithm
// Function to find the sum of contiguous subarray with maximum sum.
long long maxSubarraySum(vector<int> &arr) {
    int sum=0;
    int mx_sum=INT_MIN;
    for(int x:arr){
        sum+=x;
        mx_sum=max(mx_sum,sum);
        sum=max(0,sum);
    }
    return mx_sum;
}

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int arr[], int size){
    int cnt=0;
    int major=-1;
    for(int i=0;i<size;i++){
        if(cnt==0){
            major=arr[i];
            cnt++;
        }
        else if(major == arr[i])cnt++;
        else cnt--;
    }
    
    cnt=0;
    for(int i=0;i<size;i++){
        if(arr[i]==major)cnt++;
    }
    if(cnt>(size/2))return major;
    return -1;
}