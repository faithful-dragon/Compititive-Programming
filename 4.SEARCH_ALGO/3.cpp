// binary search
#include <iostream>
using namespace std;

// total comparision : O(log2(N))
int binary_search(int arr[], int n, int key){
    int low = 0;
    int high = n-1;
    int mid;

    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]==key)return mid;
        else if(arr[mid]<key)low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int recursive_binary_search(int low, int high, int arr[], int key){
    int mid = low + (high-low)/2;
    if(low>high)return -1;
    else if(arr[mid]==key)return mid;
    else if(arr[mid]<key)return recursive_binary_search(mid+1,high,arr,key);
    else return recursive_binary_search(low,mid-1,arr,key);
}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int idx;
    int key = 9;
    idx = binary_search(a,10,key);
    if(idx == -1)cout<<"Not found"<<endl;
    else cout<<"Found at index "<<idx<<endl;

    key=0;
    idx = binary_search(a,10,key);
    if(idx == -1)cout<<"Not found"<<endl;
    else cout<<"Found at index "<<idx<<endl;

    key = 9;
    idx = recursive_binary_search(0,9,a,key);
    if(idx == -1)cout<<"Not found"<<endl;
    else cout<<"Found at index "<<idx<<endl;

    key=0;
    idx = recursive_binary_search(0,9,a,key);
    if(idx == -1)cout<<"Not found"<<endl;
    else cout<<"Found at index "<<idx<<endl;
}