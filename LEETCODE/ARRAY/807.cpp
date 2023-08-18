#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>col(n,0),row(n,0);
        for(int i=0;i<n;i++){
            int mx1 = 0, mx2 = 0;
            for(int j=0;j<n;j++){
                mx1 = max(mx1,grid[i][j]);
                mx2 = max(mx2,grid[j][i]);
            }
            row[i] = mx2;
            col[i] = mx1;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans += min(col[j],row[i]) - grid[i][j];
            }
        }
        return ans;
    }
};