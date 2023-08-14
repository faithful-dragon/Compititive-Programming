#include <iostream>
#include <vector>
#include <map>
using namespace std;

void find_per(int *arr, int j, int n){

    if(j==n){
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    

    for(int i=j;i<n;i++){
        swap(arr[i],arr[j]);
        find_per(arr,j+1,n);
        swap(arr[i],arr[j]);
    }

}




int main(){
    int n;
    cout<<"n : ";
    cin>>n;

    cout<<"enter n elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int>ans;
    cout<<"permutations are : "<<endl;
    map<int,bool>mp;
    find_per(arr,0,n);
    return 0;
}