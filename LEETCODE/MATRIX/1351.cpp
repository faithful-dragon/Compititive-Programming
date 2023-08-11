#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=grid[i].size()-1;j>=0;j--){
                if(grid[i][j]<0)ans++;
                else break;
            }
        }
        return ans;
    }
};