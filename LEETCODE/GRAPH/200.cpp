#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;


class Solution {
public:

    bool is_valid(int i, int j, int n, int m){
        if(i<0 || i>=n)return false;
        if(j<0 || j>=m)return false;
        return true;
    }

    void dfs(int i, int j, int n, int m, vector<vector<char>>&land){
        if(is_valid(i,j,n,m)==false)return;
        if(land[i][j]=='0')return;

        land[i][j]='0';
        dfs(i+1,j,n,m,land);
        dfs(i-1,j,n,m,land);
        dfs(i,j+1,n,m,land);
        dfs(i,j-1,n,m,land);

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return cnt;
    }
};