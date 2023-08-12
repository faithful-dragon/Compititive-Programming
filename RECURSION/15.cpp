#include <iostream>
using namespace std;

void subset_sumI(int *arr, int idx, int n, int sum,vector<int>&ans){
    if(idx==n){
        ans.push_back(sum);
        return;
    }

    sum+=arr[idx];
    subset_sumI(arr,idx+1,n,sum,ans);
    sum-=arr[idx];
    subset_sumI(arr,idx+1,n,sum,ans);
}

int main(){
    int n;
    cout<<"n : ";
    cin>>n;

    cout<<"enter n elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int>ans;
    cout<<"sequences are : "<<endl;
    subset_sumI(arr,0,n,0,ans);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}