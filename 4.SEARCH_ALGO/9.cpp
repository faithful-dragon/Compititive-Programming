// single element in sorted array
#include <iostream>
#include <vector>
using namespace std;


int single_element(vector<int>arr){

    if(arr.size()==1)return arr[0];
    if(arr[0]!=arr[1])return arr[0];
    if(arr.back()!=arr[arr.size()-2])return arr.back();

    int low = 1;
    int high = arr.size()-2;
    int mid;
    
    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        cout<<low<<" "<<mid<<" "<<high<<endl;
        if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1])return arr[mid];
        else if((mid%2==1 and arr[mid]==arr[mid-1]) or (mid%2==0 and arr[mid]==arr[mid+1]))low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    vector<int>v{1,1,2,2,3,3,4,4,5,5};
    int mn = single_element(v);
    cout<<"minimum : "<<mn<<endl;

    vector<int>v1{1,1,2,2,3,3,4,5,5,6,6,7,7,8,8,9,9};
    mn = single_element(v1);
    cout<<"minimum : "<<mn<<endl;
}