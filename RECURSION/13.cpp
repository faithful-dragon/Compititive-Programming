#include <iostream>
using namespace std;

void subsequence(int *arr, int idx, int n, vector<int>sq, int target){
    if(target==0){
            for(int i=0;i<sq.size();i++)cout<<sq[i]<<" ";
            if(sq.size()==0)cout<<"{}";
            cout<<endl;
    }

    for(int i=idx;i<n;i++){
        if(i>idx and arr[i]==arr[i-1])continue;
        if(arr[i]>target)break;
        target-=arr[i];
        sq.push_back(arr[i]);
        subsequence(arr,i+1,n,sq,target);
        target+=arr[i];
        sq.pop_back();
    }
}

int main(){
    int n,sum;
    cout<<"n : ";
    cin>>n;

    cout<<"enter n elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);

    cout<<"req sum : ";
    cin>>sum;

    vector<int>sq;
    cout<<"sequences are : "<<endl;
    subsequence(arr,0,n,sq,sum);
    return 0;
}