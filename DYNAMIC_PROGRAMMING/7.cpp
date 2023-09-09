// ninja training

// 3 3
// 1 2 5
// 3 1 1
// 3 3 3
// 3 3
// 18 11 19
// 4 13 7
// 1 8 13



#include <iostream>
#include <vector>
using namespace std;


// memorization
// TC = O(N * t)
// SC = O(N) O(N * t)
int max_points(int t, int day, int last, vector<vector<int>>points, vector<vector<int>>&dp){
    if(day==0){
        int mx = 0;
        for(int i=0;i<t;i++){
            if(i != last)
            mx = max(mx, points[day][i]);
        }
        return mx;
    }

    if(dp[day][last]!=-1 and last!=-1)return dp[day][last];

    int mx_points = 0;
    for(int i=0;i<t;i++){
        if(i != last){
            int point =  points[day][i] + max_points(t,day-1,i,points,dp);
            mx_points = max(mx_points,point);
        }
    }
    dp[day][last] = mx_points;
    return mx_points;
}


//tabulation 
int max_points2(int t, int n, int day, int last, vector<vector<int>>points){
    vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], points[0][2]);
    if(day==0){
        int mx = 0;
        for(int i=0;i<t;i++){
            if(i != last)
            mx = max(mx, points[day][i]);
        }
        return mx;
    }

    if(dp[day][last]!=-1 and last!=-1)return dp[day][last];

    int mx_points = 0;
    for(int i=0;i<t;i++){
        if(i != last){
            int point =  points[day][i] + max_points(t,day-1,i,points,dp);
            mx_points = max(mx_points,point);
        }
    }
    dp[day][last] = mx_points;
    return mx_points;
}



int main(){
    int n,t;
    cin>>n>>t;

    vector<vector<int>>points(n,vector<int>(t,0));
    vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<t;j++)
        cin>>points[i][j];
    }

    int ans = max_points(t, n-1,-1,points,dp);
    cout<<"ans = "<<ans<<endl;
}