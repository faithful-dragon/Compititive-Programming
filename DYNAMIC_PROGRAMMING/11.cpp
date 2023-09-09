// min path sum in a traingluar plane
// 4
// 1
// 2 3
// 3 6 7
// 8 9 2 10


#include <iostream>
#include <vector>
using namespace std;


// TC = O(2^(n*(n+1))/2)
// SC = O(N*N)
int cnt_paths(int row, int col, int n ,vector<vector<int>>&num){
    if(row == n-1)return num[row][col];
    int down1 = num[row][col] + cnt_paths(row+1,col,n,num);
    int down2 = num[row][col] + cnt_paths(row+1,col+1,n,num);
    return min(down1, down2);
}

// TC = O(n*n)
// SC = O(N*N) + stack space
int cnt_paths1(int row, int col, int n ,vector<vector<int>>&num, vector<vector<int>>&dp){
    if(row == n-1)return dp[row][col]=num[row][col];
    if(dp[row][col]!=-1)return dp[row][col];
    int down1 = num[row][col] + cnt_paths1(row+1,col,n,num,dp);
    int down2 = num[row][col] + cnt_paths1(row+1,col+1,n,num,dp);
    return dp[row][col]=min(down1, down2);
}

// TC = O(N*N)
// SC = O(N*N)
int cnt_paths2(int n, vector<vector<int>>&num){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int j=0;j<=n;j++){
        dp[n][j] = num[n][j];
    }

    for(int i=n-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            int up1 = num[i][j] + dp[i+1][j];
            int up2 = num[i][j] + dp[i+1][j+1];
            dp[i][j] = min(up1,up2);
        }
    }

    return dp[0][0];
}

// TC = O(N+M)
// SC = O(M)
int cnt_paths3(int n,vector<vector<int>>&num){
    vector<int>prev(n+1,0);
    for(int j=0;j<=n;j++){
        prev[j] = num[n][j];
    }
    for(int i=n-1;i>=0;i--){
        vector<int>cur(n+1,0);
        for(int j=i;j>=0;j--){
            int up1 = num[i][j] + prev[j];
            int up2 = num[i][j] + prev[j+1];
            cur[j] = min(up1,up2);
        }
        prev = cur;
    }     
    return prev[0];
}



int main(){
    int n;
    cin>>n;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    vector<vector<int>>num(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++)
        cin>>num[i][j];
    }
    int paths = cnt_paths(0,0,n,num);
    cout<<"min path sum = "<<paths<<endl;
    paths = cnt_paths1(0,0,n,num,dp);
    cout<<"min path sum  = "<<paths<<endl;
    paths = cnt_paths2(n-1,num);
    cout<<"min path sum  = "<<paths<<endl;
    paths = cnt_paths3(n-1,num);
    cout<<"min path sum  = "<<paths<<endl;
}
