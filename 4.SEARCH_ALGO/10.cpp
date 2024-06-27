// peak element
#include <iostream>
#include <vector>
using namespace std;


int find_peak(vector<int>arr){

    if(arr.size()==1)return arr[0];
    if(arr[0]>arr[1])return arr[0];
    if(arr.back()>arr[arr.size()-2])return arr.back();

    int low = 1;
    int high = arr.size()-2;
    int mid;
    
    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])return arr[mid];
        else if(arr[mid]>arr[mid-1])low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    vector<int>v{1,2,1,2,3,4,2,3,4,5,6,7,8,9,8,7,8,7};
    int fp = find_peak(v);
    cout<<fp<<endl;
}