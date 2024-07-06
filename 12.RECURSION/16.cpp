#include <iostream>
#include <vector>
using namespace std;

void subsetII(int *num, int idx, int n,vector<int>&ans){
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;

    for(int i=idx;i<n;i++){
        if(i>idx and num[i]==num[i-1])continue;
        ans.push_back(num[i]);
        subsetII(num,i+1,n,ans);
        ans.pop_back();
    }
}

int main(){
    int n;
    cout<<"n : ";
    cin>>n;

    cout<<"enter n elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);

    vector<int>ans;
    cout<<"sequences are : "<<endl;
    subsetII(arr,0,n,ans);
    return 0;
}