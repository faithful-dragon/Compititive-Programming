#include <iostream>
#include <vector>
using namespace std;

// 0 1 1 2 3 5 8 13 ....
// TC = O(N)
// SC = 2*O(N)

int fib1(int n, vector<int>&dp){
    if(n<=1)return dp[n] = n;
    else if(dp[n]!=-1) return dp[n];
    else return dp[n] = fib1(n-1,dp) + fib1(n-2,dp);
}

int main(){
    int t;
    cin>>t;
    vector<int>dp(t+1,-1);
    int nth = fib1(t,dp);
    cout<<t<<"th fib no : "<<nth<<endl;
    return 0;
}