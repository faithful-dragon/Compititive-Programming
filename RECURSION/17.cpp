#include <iostream>
#include <vector>
#include <map>
using namespace std;

void find_per(int *arr, int idx, int n, vector<int>per,map<int,bool>mp){
    if(per.size()==n){
        for(int i=0;i<n;i++)cout<<per[i]<<" ";
        cout<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(mp[i]==false){
            per.push_back(arr[i]);
            mp[i]=true;
            find_per(arr,i+1,n,per,mp);
            per.pop_back();
            mp[i]=false;
        }
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
    find_per(arr,0,n,ans,mp);
    return 0;
}