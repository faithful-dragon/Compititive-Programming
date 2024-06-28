// floor and ceil
#include <iostream>
#include <vector>
using namespace std;

int floor(vector<int> &arr, int n, int key){   // largest <= key
    int low = 0;
    int high = n-1;
    int mid;
    int ans = n;
    
    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]<=key){
            low=mid+1;
            ans=mid;
        }
        else high=mid-1;
    }
    return ans;
}
    
    // total comparision : O(log2(N))
int ceil(vector<int> &arr, int n, int key){   // smallest >=key
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

int main(){
    const int n = 13;
    vector<int>v{1,3,4,4,4,4,5,6,7,8,9,20};
    int x = 10;
    int low = floor(v,n,x);
    int high = ceil(v,n,x);
    if(low==n)cout<<"not found"<<endl;
    else cout<<"floor value : "<<v[low]<<endl;
    if(high==n)cout<<"not found"<<endl;
    else cout<<"ceil value : "<<v[high]<<endl;

    x = 2;
    low = floor(v,n,x);
    high = ceil(v,n,x);
    if(low==n)cout<<"not found"<<endl;
    else cout<<"floor value : "<<v[low]<<endl;
    if(high==n)cout<<"not found"<<endl;
    else cout<<"ceil value : "<<v[high]<<endl;

}