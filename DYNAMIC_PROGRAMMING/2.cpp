#include <iostream>
#include <vector>
using namespace std;


// memorization
int possible_ways(int n, vector<int>&dp){
    if(n<0)return 0;
    else if(n<=2)return dp[n]=1;
    else if(dp[n]!=-1)return dp[n];
    else return dp[n]=possible_ways(n-1, dp) + possible_ways(n-2, dp);
}

int main(){
    int t;
    cin>>t;
    vector<int>dp(t+2,-1);
    int x = possible_ways(t+1,dp);
    cout<<"no of possoble ways :  "<<x<<endl;
    return 0;
}

