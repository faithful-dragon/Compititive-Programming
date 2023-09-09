#include <iostream>
#include <vector>
using namespace std;

// 0 1 1 2 3 5 8 13 ....
// TC = O(N)
// SC = 2*O(N)

// memorization
int fib1(int n, vector<int>&dp){
    if(n<=1)return dp[n] = n;
    else if(dp[n]!=-1) return dp[n];
    else return dp[n] = fib1(n-1,dp) + fib1(n-2,dp);
}

// tabulation  : from base case to solution
// TC = O(N)
// SC = O(N)  : reducing recurssion stack space
int fib2(int n){
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// memory optimization
// TC = O(N)
// SC = O(1)
int fib3(int n){
    if(n<=1)return 1;
    int prev1 = 1;
    int prev2 = 0;
    int next;
    for(int i=2;i<=n;i++){
        next = prev1 + prev2;
        prev2 = prev1;
        prev1 = next;
    }
    return next;
}


int main(){
    int t;
    cin>>t;
    vector<int>dp(t+1,-1);
    int nth = fib1(t,dp);
    cout<<t<<"th fib no : "<<nth<<endl;
    nth = fib2(t);
    cout<<t<<"th fib no : "<<nth<<endl;
    nth = fib3(t);
    cout<<t<<"th fib no : "<<nth<<endl;
    return 0;
}