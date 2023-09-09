// max path sum from top to bottom sum

// 4 4
// 1 2 10 4
// 100 3 2 1
// 1 1 20 2
// 1 2 2 1


#include <iostream>
#include <vector>
using namespace std;


//Recurssion
// TC = O(3^N)
// SC = O(N)
int max_sum(int row, int col, int m, vector<vector<int>>&num){
    if(col<0 or col>=m)return -1e9;
    if(row == 0)return num[row][col];

    int up = num[row][col] + max_sum(row-1,col,m,num);
    int up_left = num[row][col] + max_sum(row-1,col-1,m,num);
    int up_right = num[row][col] + max_sum(row-1,col+1,m,num);
    return max(up , max(up_right, up_left));
}

// Memoizatoin
// TC = O(N*M)
// SC = O(N) + O(N*M)
int max_sum1(int row, int col, int m, vector<vector<int>>&num, vector<vector<int>>&dp){
    if(col<0 or col>=m)return -1e9;
    if(row == 0)return num[row][col];
    if(dp[row][col]!=-1)return dp[row][col];

    int up = num[row][col] + max_sum1(row-1,col,m,num,dp);
    int up_left = num[row][col] + max_sum1(row-1,col-1,m,num,dp);
    int up_right = num[row][col] + max_sum1(row-1,col+1,m,num,dp);
    return dp[row][col] = max(up , max(up_right, up_left));
}

// Tabulation
// TC = O(N*M)
// SC = O(N*M)
int max_sum2(int n, int m, vector<vector<int>>&num){
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int j=0;j<m;j++){
        dp[0][j] = num[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int down = -1e9;
            int down_left = -1e9;
            int down_right = -1e9;
            down = num[i][j] + dp[i-1][j];
            if(down_left>0)down_left = num[i][j] + dp[i-1][j-1];
            if(down_right<m)down_right = num[i][j] + dp[i-1][j+1];
            dp[i][j] = max(down , max(down_left, down_right));
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i][m-1]);
    }
    return ans;
}



// Space optmization
// TC = O(N*M)
// SC = O(N)
int max_sum3(int n, int m, vector<vector<int>>&num){
    vector<int>prev(m,0);
    for(int j=0;j<m;j++){
        prev[j] = num[0][j];
    }

    for(int i=1;i<n;i++){
        vector<int>cur(m,0);
        for(int j=0;j<n;j++){
            int down = -1e9;
            int down_left = -1e9;
            int down_right = -1e9;
            down = num[i][j] + cur[j];
            if(down_left>0)down_left = num[i][j] + prev[j-1];
            if(down_right<m)down_right = num[i][j] + prev[j+1];
            cur[j] = max(down , max(down_left, down_right));
        }
        prev = cur;
    }

    return prev.back();
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

    int ans=0;
    for(int j=0;j<m;j++){
        int paths = max_sum(n-1,j,m,num);
        ans = max(ans,paths);
    }
    cout<<"min path sum = "<<ans<<endl;

    ans=0;
    for(int j=0;j<m;j++){
        int paths = max_sum1(n-1,j,m,num,dp);
        ans = max(ans,paths);
    }
    cout<<"min path sum = "<<ans<<endl;

    int paths = max_sum2(n,m,num);
    cout<<"min path sum = "<<ans<<endl;

    paths = max_sum3(n,m,num);
    cout<<"min path sum = "<<ans<<endl;

}
