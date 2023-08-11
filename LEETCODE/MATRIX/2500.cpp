#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(vector<int>&v:grid){
            sort(v.begin(),v.end());
        }
        int ans=0,x=0;
        for(int j=0;j<grid[0].size();j++){
            x=0;
            for(int i=0;i<grid.size();i++){
                x=max(x,grid[i][j]);
            }
            ans+=x;
        }
        return ans;
    }
};