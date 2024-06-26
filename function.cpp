#include <iostream>
#include <vector>
using namespace std;

string toLower(string s) {
    for(int i=0;i<s.length();i++){
        if((int)s[i] < 91)s[i]+=32;
    }
    return s;
}

string to_upper(string s){
    for(int i=0;i<s.length();i++){
        if((int)s[i] > 91)s[i]-=32;
    }
    return s;
}

bool vower(char c){
    if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return true;
    return false;
}

int binarysearch(int arr[], int n, int k) {
    int low = 0;
    int high = n;
    
    while(low<high){
        int mid = low + (high-low)/2;
        if(arr[mid]==k)return mid;
        else if(arr[mid]<k)low = mid+1;
        else high = mid;
    }
    return -1;
}

//Function to reverse every sub-array group of size k.
void reverseInGroups(vector<long long>& arr, int n, int k){
    for(int i=0;i<n;i+=k){
        int low = i;
        int high = min(i+k,n);
        reverse(arr.begin()+low,arr.begin()+high);
    }
}

// Given an array of size n. The task is to rotate array by d elements where d ≤ n.
void leftRotate(int arr[], int n, int d) {
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}

// third largest number
int thirdLargest(int arr[], int n){
    int a=-1;
    int b=-1;
    int c=-1;
    for(int i=0;i<n;i++){
        if(a<arr[i]){
            if(b<arr[i]){
                if(c<arr[i]){
                    a=b;
                    b=c;
                    c=arr[i];
                }
                else{
                    a=b;
                    b=arr[i];
                }
            }
            else a=arr[i];
        }
    }
    return a;
}

string reverseString(string str){
        int i=0;
        int j=str.length()-1;
        while(i<j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
        return str;
    }