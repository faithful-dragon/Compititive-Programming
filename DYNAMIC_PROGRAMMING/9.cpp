// no of unique path 0,0 -> n-1, m-1 having obstacles
// 3 3
// 0 0 0  
// 0 -1 0
// 0 0 0


#include <iostream>
#include <vector>
using namespace std;


// TC = O(2^nm)
// SC = O((n-1)*(m-1))
int cnt_paths(int i, int j, vector<vector<int>>&num){
    if(i==0 and j==0)return 1;
    if(i<0 or j<0) return 0;
    if(num[i][j]==-1)return 0;

    int up = cnt_paths(i-1,j,num);
    int lt = cnt_paths(i,j-1,num);
    return up+lt;
}

// TC = O(N+M)
// SC = O((n-1)*(m-1)) + O(N*M)
int cnt_paths1(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&num){
    if(i==0 and j==0)return dp[i][j]=1;
    if(i<0 or j<0) return 0;
    if(num[i][j]==-1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up = cnt_paths1(i-1,j,dp,num);
    int lt = cnt_paths1(i,j-1,dp,num);
    return dp[i][j]=up+lt;
}

// TC = O(N+M)
// SC = O(N*M)
int cnt_paths2(int n, int m, vector<vector<int>>&num){
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(num[i][j]==-1)dp[i][j]=0;
            else if(i==0 and j==0)dp[i][j]=1;
            else{
                int up = 0;
                int lt = 0;
                if(i>0 and num[i-1][j] != -1)up = dp[i-1][j];
                if(j>0 and num[i][j-1] != -1)lt = dp[i][j-1];
                dp[i][j]=up+lt;
            }
        }
    }     
    return dp[n][m];
}

// TC = O(N+M)
// SC = O(M)
int cnt_paths3(int n, int m, vector<vector<int>>&num){
    vector<int>prev(m+1,0);
    prev[0]=1;
    for(int i=0;i<=n;i++){
        vector<int>cur(m+1,0);
        for(int j=0;j<=m;j++){
            if(num[i][j]==-1)cur[j]=0;
            else if(i==0 and j==0)cur[j]=1;
            else{
                int up = 0;
                int lt = 0;
                if(i>0 and num[i-1][j] != -1)up = prev[j];
                if(j>0 and num[i][j-1] != -1)lt = cur[j-1];
                cur[j]=up+lt;
            }
        }
        prev = cur;
    }     
    return prev[m];
}



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    vector<vector<int>>num(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>num[i][j];
    }
    int paths = cnt_paths(n-1,m-1,num);
    cout<<"no of paths = "<<paths<<endl;
    paths = cnt_paths1(n-1,m-1,dp,num);
    cout<<"no of paths = "<<paths<<endl;
    paths = cnt_paths2(n-1,m-1,num);
    cout<<"no of paths = "<<paths<<endl;
    paths = cnt_paths3(n-1,m-1,num);
    cout<<"no of paths = "<<paths<<endl;
}
