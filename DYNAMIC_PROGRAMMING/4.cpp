// frog with at max k jumps
#include <iostream>
#include <vector>
using namespace std;

// 8 4
// 7 4 4 2 6 6 3 4


// memorization
// TC = O(N)*K
// SC = 2*O(N)
int minEnergy1(int j, int k, vector<int>&dp, vector<int>tower){
    if(j==0)return 0;
    int eng = INT_MAX;
    if(dp[j]!=-1)return dp[j];
    for(int i=1;i<=k;i++){
        int ans = INT_MAX;
        if(j-i >= 0) ans = minEnergy1(j-i,k,dp, tower) + abs(tower[j]-tower[j-i]);
        eng = min(eng,ans);
    }
    return dp[j]=eng;
}



// tabulation
// TC = O(N)*K
// SC = O(N)
int minEnergy2(int n, int k, vector<int>tower){
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++){
        int eng = INT_MAX;
        for(int j=1;j<=k;j++){
            int ans = INT_MAX;
            if(i-j>=0){
                ans = dp[i-j] + abs(tower[i]-tower[i-j]);
            }
            eng = min(eng,ans);
        }
        dp[i] = eng;
    }
    for(int x:dp)cout<<x<<" ";cout<<endl;
    return dp[n];
}



int main(){
    int n,k;
    cin>>n>>k;
    vector<int>height(n);
    for(int i=0;i<n;i++)
        cin>>height[i];
    vector<int>dp(n+1,-1);
    int energy = minEnergy1(n-1,k,dp,height);
    for(int x:dp)cout<<x<<" ";cout<<endl;
    cout<<"min energy : "<<energy<<endl;
    energy = minEnergy2(n-1,k,height);
    cout<<"min energy : "<<energy<<endl;
    // energy = minEnergy3(n,height);
    // cout<<"min energy : "<<energy<<endl;
    return 0;
}