// subsequence with sum = k
// 4 5
// 4 3 2 1
// 5 4
// 2 5 1 6 7



#include <iostream>
#include <vector>
using namespace std;


// RECURSSION
// TC = O(2^N)
// SC = O(N)
bool sub_sum(int i, int k, vector<int>v){
    if(k==0) return true;
    if(i==0) return v[i]==k;
    bool pick = false;
    if(v[i]<=k) pick = sub_sum(i-1,k-v[i],v);
    bool not_pick = sub_sum(i-1,k,v);
    return pick or not_pick;
}

// MEMOIZATION
// TC = O(N*T)
// SC = O(N*T) + O(N)
bool sub_sum1(int i,int k, vector<int>v,  vector<vector<int>>&dp){
    if(k==0) return true;
    if(i==0) return v[i]==k;
    if(dp[i][k]!=-1)return dp[i][k];
    bool pick = false;
    if(v[i]<=k) pick = sub_sum1(i-1,k-v[i],v,dp);
    bool not_pick = sub_sum1(i-1,k,v,dp);
    return dp[i][k]= (pick or not_pick);
}


// TABULATION
// TC = O(N*T)
// SC = O(N*T)
bool sub_sum2(int n, int k, vector<int>v){
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)dp[i][0]=true;
    dp[0][v[0]] = true;

    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool pick = false;
            if(v[i]<=target) pick = dp[i-1][target-v[i]];
            bool not_pick = dp[i-1][target];
            dp[i][target]= (pick or not_pick);
        }
    }
    return dp[n-1][k];
}


// SPACE OPTIMIZATION
// TC = O(N*T)
// SC = O(K)
bool sub_sum3(int n, int k, vector<int>v){
    vector<bool>prev(k+1,0);
    prev[0]=true;
    prev[v[0]] = true;

    for(int i=1;i<n;i++){
        vector<bool>curr(k+1,0);
        for(int target=1;target<=k;target++){
            bool pick = false;
            if(v[i]<=target) pick = prev[target-v[i]];
            bool not_pick = prev[target];
            curr[target]= (pick or not_pick);
        }
        prev = curr;
    }
    return prev[k];
}


int main(){
    int n, target;
    cin>>n>>target;

    vector<int>v(n);
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    bool found = sub_sum(n-1,target,v);
    cout<<"found : "<<found<<endl;
    found = sub_sum1(n-1,target,v,dp);
    cout<<"found : "<<found<<endl;
    found = sub_sum2(n,target,v);
    cout<<"found : "<<found<<endl;
    found = sub_sum3(n,target,v);
    cout<<"found : "<<found<<endl;
}