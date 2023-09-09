// counts subsets with sum = K
// 5 5
// 1 2 3 4 5
// 4 3
// 1 2 2 3
#include <iostream>
#include <vector>
using namespace std;


// RECURSSION
// TC = O(2^N)
// SC = O(N)
int cnt_subset(int n, int tar, vector<int>&v){
    if(tar==0)return 1;
    if(n==0)return tar == v[0];
    int cnt = 0;
    cnt += cnt_subset(n-1,tar,v);
    if(v[n]<=tar) cnt += cnt_subset(n-1,tar-v[n],v);

    return cnt;
}

// MEMOIZATION
// TC = O(N*T)
// SC = O(N*T) + O(N)
int cnt_subset1(int n, int tar, vector<int>&v, vector<vector<int>>&dp){
    if(tar==0)return 1;
    if(n==0)return tar == v[0];
    if(dp[n][tar]!=-1)return dp[n][tar];
    int cnt = 0;
    cnt += cnt_subset1(n-1,tar,v,dp);
    if(v[n]<=tar) cnt += cnt_subset1(n-1,tar-v[n],v,dp);

    return dp[n][tar] = cnt;
}

// TABULATION
// TC = O(N*T)
// SC = O(N*T)
int cnt_subset2(int n, int tar, vector<int>&v){
    vector<vector<int>>dp(n+1,vector<int>(tar+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    if(v[0]<=tar) dp[0][v[0]] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=tar;j++){
            int cnt = 0;
            cnt += dp[i-1][j];
            if(v[i]<=j) cnt += dp[i-1][j-v[i]];
            dp[i][j] = cnt;
        }
    }

    return dp[n-1][tar];
}


// SPACE OPTMIZATION
// TC = O(N*T)
// SC = O(T)
int cnt_subset3(int n, int tar, vector<int>&v){
    vector<int>prev(tar+1,0);
    prev[0] = 1;
    if(v[0]<=tar) prev[v[0]] = 1;
    for(int i=1;i<n;i++){
        vector<int>curr(tar+1,0);
        for(int j=0;j<=tar;j++){
            int cnt = 0;
            cnt += prev[j];
            if(v[i]<=j) cnt += prev[j-v[i]];
            curr[j] = cnt;
        }
        prev = curr;
    }

    return prev[tar];
}

int main(){
    int n,t;
    cin>>n>>t;

    vector<int>v(n);
    vector<vector<int>>dp(n,vector<int>(t+1,-1));
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int cnt = 0;
    cnt = cnt_subset(n-1,t,v);
    cout<<"no of subseq = "<<cnt<<endl;
    cnt = cnt_subset1(n-1,t,v,dp);
    cout<<"no of subseq = "<<cnt<<endl;
    cnt = cnt_subset2(n,t,v);
    cout<<"no of subseq = "<<cnt<<endl;
    cnt = cnt_subset3(n,t,v);
    cout<<"no of subseq = "<<cnt<<endl;
    return 0;
}