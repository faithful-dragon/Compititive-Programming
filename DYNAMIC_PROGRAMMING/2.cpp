#include <iostream>
#include <vector>
using namespace std;


// memorization
// TC = O(N)
int climbStairs1(int n, vector<int>&dp){
    if(n<0)return 0;
    else if(n<=1)return dp[n]=1;
    else if(dp[n]!=-1)return dp[n];
    else return dp[n]=climbStairs1(n-1, dp) + climbStairs1(n-2, dp);
}


// tabulation
// TC = O(N)
// SC = O(N)
int climbStairs2(int n) {
    if(n<=2)
        return n;
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    
    return dp[n];
}



// memory optimization
// TC = O(N)
// SC = O(1)
int climbStairs3(int n){
    if(n<=2)return n;
    int prev1 = 2;
    int prev2 = 1;
    int next;
    for(int i=3;i<=n;i++){
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
    int x = climbStairs1(t,dp);
    cout<<"no of possoble ways :  "<<x<<endl;
    x = climbStairs2(t);
    cout<<"no of possoble ways :  "<<x<<endl;
    x = climbStairs3(t);
    cout<<"no of possoble ways :  "<<x<<endl;
    return 0;
}

