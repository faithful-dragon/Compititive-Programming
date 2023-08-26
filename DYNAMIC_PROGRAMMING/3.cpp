#include <iostream>
#include <vector>
using namespace std;

// 8
// 7 4 4 2 6 6 3 4


// memorization
// TC = O(N)
// SC = 2*O(N)
int minEnergy1(int n, vector<int>&dp, vector<int>tower){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int left = minEnergy1(n-1,dp, tower) + abs(tower[n]-tower[n-1]);
    int right=INT_MAX;
    if(n>1) right = minEnergy1(n-2,dp, tower) + abs(tower[n]-tower[n-2]);
    return dp[n]=min(left, right);
}


// tabulation
// TC = O(N)
// SC = O(N)
int minEnergy2(int n,vector<int>tower){
    vector<int>dp(n,0);
    for(int i=1;i<n;i++){
        int l = dp[i-1] + abs(tower[i]-tower[i-1]);
        int r = INT_MAX;
        if(i>1) r = dp[i-2] + abs(tower[i]-tower[i-2]);
        dp[i] = min(l,r);
    }
    return dp[n-1];
}

// memory optimization
// TC = O(N)
// SC = O(1)
int minEnergy3(int n,vector<int>tower){
    int prev1=0;
    int prev2=0;
    int curr =0;
    for(int i=1;i<n;i++){
        int fs = prev1 + abs(tower[i] - tower[i-1]);
        int sc = INT_MAX;
        if(i>1) sc = prev2 + abs(tower[i] - tower[i-2]);
        curr = min(fs,sc);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}



int main(){
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i=0;i<n;i++)
        cin>>height[i];
    vector<int>dp(n+1,-1);
    int energy = minEnergy1(n-1,dp,height);
    cout<<"min energy : "<<energy<<endl;
    energy = minEnergy2(n,height);
    cout<<"min energy : "<<energy<<endl;
    energy = minEnergy3(n,height);
    cout<<"min energy : "<<energy<<endl;
    return 0;
}