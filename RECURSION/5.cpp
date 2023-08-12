#include <iostream>
using namespace std;


void reverse_array(int *arr, int i, int n){
    if(i==n)return;
    swap(arr[i],arr[n]);
    reverse_array(arr,i+1,n-1);
}

int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    int *arr = new int[n];
    cout<<"enter elements of array : ";
    for(int i=0;i<n;i++)cin>>arr[i];

    reverse_array(arr,0,n-1);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}