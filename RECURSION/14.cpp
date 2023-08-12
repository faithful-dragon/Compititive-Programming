#include <iostream>
using namespace std;

void sub_set(int *arr, int idx, int n, vector<int>sq){
    if(idx==n){
        for(int i=0;i<sq.size();i++){
            cout<<sq[i]<<" ";
        }
        if(sq.size()==0)cout<<"{}";
        cout<<endl;
        return;
    }

    sq.push_back(arr[idx]);
    sub_set(arr,idx+1,n,sq);
    sq.pop_back();
    sub_set(arr,idx+1,n,sq);
}

int main(){
    int n,sum;
    cout<<"n : ";
    cin>>n;

    cout<<"enter n elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int>sq;
    cout<<"sequences are : "<<endl;
    sub_set(arr,0,n,sq);
    return 0;
}