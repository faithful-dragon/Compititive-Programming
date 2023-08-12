#include <iostream>
using namespace std;

void subsequence(int *arr, int i, int n, vector<int>sq, int sum){
    if(i==n){
        if(sum==0){
            for(int i=0;i<sq.size();i++)cout<<sq[i]<<" ";
            if(sq.size()==0)cout<<"{}";
            cout<<endl;
        }
        return;
    }

    if(arr[i]<=sum){
        sq.push_back(arr[i]);
        sum-=arr[i];
        subsequence(arr,i,n,sq,sum);
        sq.pop_back();
        sum+=arr[i];
    }
    subsequence(arr,i+1,n,sq,sum);
}

int main(){
    int n,sum;
    cout<<"n : ";
    cin>>n;

    cout<<"enter n elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<"req sum : ";
    cin>>sum;

    vector<int>sq;
    cout<<"sequences are : "<<endl;
    subsequence(arr,0,n,sq,sum);
    return 0;
}