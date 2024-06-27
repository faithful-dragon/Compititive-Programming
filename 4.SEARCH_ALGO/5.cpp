// first and last occurence
#include <iostream>
#include <vector>
using namespace std;

int first_occur(vector<int> &arr, int n, int key){
    int low = 0;
    int high = n-1;
    int mid;
    int ans = n;
    
    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]==key){
            high=mid-1;
            ans=mid;
        }
        else if(arr[mid]<key)low=mid+1;
        else high=mid-1;
    }
    return ans;
}
    
    // total comparision : O(log2(N))
int last_occur(vector<int> &arr, int n, int key){
    int low = 0;
    int high = n-1;
    int mid;
    int ans = n;

    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]==key){
            low=mid+1;
            ans=mid;
        }
        else if(arr[mid]<key)low=mid+1;
        else high=mid-1;
    }
    return ans;
}

int main(){
    const int n = 13;
    vector<int>v{1,2,3,4,4,4,4,5,6,7,8,9,20};
    int x = 4;
    int low = first_occur(v,n,x);
    int high = last_occur(v,n,x);
    if(low==n or high==n)cout<<"not found"<<endl;
    else{
        cout<<"first occur at "<<low<<endl;
        cout<<"last occur at "<<high<<endl;
    }

}