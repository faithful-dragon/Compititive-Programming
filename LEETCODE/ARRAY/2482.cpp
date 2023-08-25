#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>row1(n),row0(n);
        vector<int>col1(m),col0(m);

        int one,zero;
        for(int i=0;i<n;i++){
            one=0;zero=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)one++;
                else zero++;
            }
            row1[i]=one;
            row0[i]=zero;
        }

        for(int j=0;j<m;j++){
            one=0;zero=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1)one++;
                else zero++;
            }
            col1[j]=one;
            col0[j]=zero;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = (row1[i] + col1[j]) - (row0[i] + col0[j]);
            }
        }
        
        return grid;
    }
};