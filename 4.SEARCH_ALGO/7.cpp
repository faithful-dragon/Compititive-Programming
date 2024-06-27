// search in rotated sorted array
#include <iostream>
#include <vector>
using namespace std;

// array with uniqe elements
int search(vector<int> &arr, int n, int key){   
    int low = 0;
    int high = n-1;
    int mid;
    
    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]==key) return mid;
        else if(arr[low]<=arr[mid]){      // left sorted
            if(key>=arr[low] and key<=arr[mid])
                high = mid-1;
            else low=mid+1;
        } 
        else{                             // right sorted
            if(key>=arr[mid] and key<=arr[high]) 
                low = mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

// array with dublicate elements
int search2(vector<int> &arr, int n, int key){   
    int low = 0;
    int high = n-1;
    int mid;
    
    while(low<=high){
        mid = low + (high-low)/2;         // to overcome overflow
        if(arr[mid]==key) return mid;
        else if(arr[mid]==arr[low] and arr[mid]==arr[high]){  // check condition
            low++;
            high--;
            continue;
        }
        else if(arr[low]<=arr[mid]){      // left sorted
            if(key>=arr[low] and key<=arr[mid])
                high = mid-1;
            else low=mid+1;
        } 
        else{                             // right sorted
            if(key>=arr[mid] and key<=arr[high]) 
                low = mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

int main(){
    const int n = 13;
    vector<int>v{8,9,10,11,12,13,1,2,3,4,5,6,7};
    int x = 10;
    int idx = search(v,n,x);
    if(idx==-1)cout<<"Not found"<<endl;
    else cout<<"found at index "<<idx<<endl;

    x = 4;
    idx = search(v,n,x);
    if(idx==-1)cout<<"Not found"<<endl;
    else cout<<"found at index "<<idx<<endl;

    x = 0;
    idx = search(v,n,x);
    if(idx==-1)cout<<"Not found"<<endl;
    else cout<<"found at index "<<idx<<endl;

    cout<<endl<<endl;

    const int m=9;
    vector<int>v1{3,1,2,3,3,3,3,3,3};
    x = 10;
    idx = search(v1,m,x);
    if(idx==-1)cout<<"Not found"<<endl;
    else cout<<"found at index "<<idx<<endl;

    x = 3;
    idx = search(v1,m,x);
    if(idx==-1)cout<<"Not found"<<endl;
    else cout<<"found at index "<<idx<<endl;

    x = 1;
    idx = search(v1,m,x);
    if(idx==-1)cout<<"Not found"<<endl;
    else cout<<"found at index "<<idx<<endl;   // got wrong answer

    idx = search2(v1,m,x);
    if(idx==-1)cout<<"Not found"<<endl;
    else cout<<"found at index "<<idx<<endl;
}