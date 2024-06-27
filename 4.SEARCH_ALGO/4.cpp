// lower and upper bound
#include <iostream>
using namespace std;

// total comparision : O(log2(N))
int lower_bound(int arr[], int n, int key){
    int low = 0;
    int high = n-1;
    int mid;
    int ans = n;

    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]>=key){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}

// total comparision : O(log2(N))
int upper_bound(int arr[], int n, int key){
    int low = 0;
    int high = n-1;
    int mid;
    int ans = n;

    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]>key){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}

int main(){
    const int n=10;
    int a[n] = {1,2,3,3,5,8,8,10,10,11};
    int idx;
    int key = 6;
    idx = lower_bound(a,n,key);
    if(idx == n)cout<<"Not found"<<endl;
    else cout<<"lower bound at index "<<idx<<endl;

    key=11;
    idx = lower_bound(a,n,key);
    if(idx == n)cout<<"Not found"<<endl;
    else cout<<"lower bound at index "<<idx<<endl;

    key = 6;
    idx = upper_bound(a,n,key);
    if(idx == n)cout<<"Not found"<<endl;
    else cout<<"upper bound at index "<<idx<<endl;

    key=5;
    idx = upper_bound(a,n,key);
    if(idx == n)cout<<"Not found"<<endl;
    else cout<<"upper bound at index "<<idx<<endl;

    key=3;
    idx = lower_bound(a,n,key);
    if(idx == n)cout<<"Not found"<<endl;
    else cout<<"lower bound at index "<<idx<<endl;

    key = 3;
    idx = upper_bound(a,n,key);
    if(idx == n)cout<<"Not found"<<endl;
    else cout<<"upper bound at index "<<idx<<endl;
}