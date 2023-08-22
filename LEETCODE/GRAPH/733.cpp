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

    void paint(int i, int j, int oc,int nc, int n, int m, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        if(is_valid(i,j,n,m)==false)return;
        if(vis[i][j]==true)return;
        if(grid[i][j]==nc)return;

        if(grid[i][j]==oc){
            vis[i][j]=true;
            grid[i][j] =nc;
            paint(i+1,j,oc,nc,n,m,grid,vis);
            paint(i-1,j,oc,nc,n,m,grid,vis);
            paint(i,j+1,oc,nc,n,m,grid,vis);
            paint(i,j-1,oc,nc,n,m,grid,vis);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oc = image[sr][sc];
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        paint(sr,sc,oc,color,n,m,image,vis);
        return image;
    }
};