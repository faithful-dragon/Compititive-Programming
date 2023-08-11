#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=n-3;
        vector<int>v;
        vector<vector<int>>ans;

        int mx=0,a=0,b=0;
        while(true){
            for(int i=a;i<3+a;i++){
                for(int j=b;j<3+b;j++){
                    mx=max(mx,grid[i][j]);
                }
            }
            v.push_back(mx);
            mx=0;
            b++;
            if(b>m){
                ans.push_back(v);
                v.clear();
                b=0;
                a++;
                if(a>m)break;
            }
            if(a>m)break;
        }
        return ans;
    }
};