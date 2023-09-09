// max sum of subsequence with no adj element

// 3
// 1 2 3
// 4
// 2 1 4 9

#include <iostream>
#include <vector>
using namespace std;


// memorization
// TC = O(N)
// SC = 2*O(N)
int max_sum1(int i, vector<int>num, vector<int>&dp){
    if(i==0)return num[0];
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];

    int pick = num[i] + max_sum1(i-2,num,dp);
    int not_pick = 0 + max_sum1(i-1,num,dp);

    return dp[i] = max(pick,not_pick);
}


// tabulation
// TC = O(N)
// SC = O(N)
int max_sum2(int n, vector<int>num){
    vector<int>dp(n+1,0);
    dp[0] = num[0];
    for(int i=1;i<n;i++){
        int pick = num[i];
        if(i>1)pick+=dp[i-2];
        int not_pick = 0 + dp[i-1];
        dp[i] = max(pick,not_pick);
    }
    return dp[n-1];
}


//space optimization
// TC = O(N)
// SC = O(2)
int max_sum3(vector<int>num){
    int prev1 = num[0];
    int prev2 = 0;
    for(int i=1;i<num.size();i++){
        int pick = num[i];
        if(i>1)pick+=prev2;
        int not_pick = 0 + prev1;
        prev2 = prev1;
        prev1 = max(pick, not_pick);
    }
    return prev1;
}


int main(){
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++)
        cin>>num[i];
    vector<int>dp(n+1,-1);
    int sum = max_sum1(n-1,num,dp);
    for(int x:dp)cout<<x<<" ";cout<<endl;
    cout<<"max sum : "<<sum<<endl;
    sum = max_sum2(n,num);
    cout<<"max sum : "<<sum<<endl;
    sum = max_sum3(num);
    cout<<"max sum : "<<sum<<endl;
    return 0;
}
