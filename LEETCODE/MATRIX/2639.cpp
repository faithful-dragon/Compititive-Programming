#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>ans;
        for(int j=0;j<grid[0].size();j++){
            int l=0;
            for(int i=0;i<grid.size();i++){
                int x = grid[i][j];
                int a;
                if(x==0)a=0;
                else a = log10(abs(x));
                if(x<0)a++;
                l=max(l,a+1);
            }
            ans.push_back(l);
        }
        return ans;
    }
};
