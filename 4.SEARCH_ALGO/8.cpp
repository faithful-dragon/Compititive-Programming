// minimum in rotated sorted array or no of times array is rotated
#include <iostream>
#include <vector>
using namespace std;

int search_min(vector<int> &arr){  
    int low = 0;
    int high = arr.size()-1;
    int mid;
    int mn=INT_MAX;
    
    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[low]<=arr[mid]){
            mn = min(mn,arr[low]);
            low=mid+1;
        }
        else{
            mn = min(mn,arr[mid]);
            high=mid-1;
        }
    }
    return mn;
}

int no_of_rot(vector<int>arr){
    int low = 0;
    int high = arr.size()-1;
    int mid;
    int mn=INT_MAX;
    int rot=0;
    
    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[low]<=arr[mid]){
            if(mn>arr[low]){
                mn=arr[low];
                rot=low;
            }
            
            low=mid+1;
        }
        else{
            if(mn>arr[mid]){
                mn=arr[mid];
                rot=mid;
            }
            high=mid-1;
        }
    }
    return rot;
}

int main(){
    const int n = 13;
    vector<int>v{8,9,10,11,12,13,1,2,3,4,5,6,7};
    int mn = search_min(v);
    cout<<"minimum : "<<mn<<endl;
    int rot = no_of_rot(v);
    cout<<"rotation : "<<rot<<endl;

    vector<int>v1{3,1,2,3,3,3};
    mn = search_min(v1);
    cout<<"minimum : "<<mn<<endl;
    rot = no_of_rot(v1);
    cout<<"rotation : "<<rot<<endl;
}