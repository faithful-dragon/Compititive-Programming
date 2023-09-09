// subset with min sum differnce
// 3
// 4 5 6
// 3
// 1 2 3

#include <iostream>
#include <vector>
using namespace std;


int min_diff(int n, vector<int>&v){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    if(v[0]<=sum)dp[0][v[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            bool pick = dp[i-1][j];
            bool not_pick = false;
            if(v[i]<=j)not_pick = dp[i-1][j-v[i]];
            dp[i][j] = (pick | not_pick);
        }
    }

    int mn = 1e9;
    for(int i=0;i<=sum/2;i++){
        if(dp[n-1][i]==true)
        mn = min(mn,abs(i-(sum-i)));
    }

    return mn;
}


int min_diff1(int n, vector<int>&v){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    vector<bool>prev(sum+1,false);
    prev[0]=true;
    if(v[0]<=sum)prev[v[0]]=true;

    for(int i=1;i<n;i++){
        vector<bool>curr(sum+1,false);
        for(int j=0;j<=sum;j++){
            bool pick = prev[j];
            bool not_pick = false;
            if(v[i]<=j)not_pick = prev[j-v[i]];
            curr[j] = (pick | not_pick);
        }
        prev = curr;
    }

    int mn = 1e9;
    for(int i=0;i<=sum/2;i++){
        if(prev[i]==true)
        mn = min(mn,abs(i-(sum-i)));
    }
    return mn;
}


int main(){
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }

    int mn_diff;
    mn_diff = min_diff(n,v);
    cout<<"ans = "<<mn_diff<<endl;
    mn_diff = min_diff1(n,v);
    cout<<"ans = "<<mn_diff<<endl;
    return 0;
}
