#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>min_row(n);
        vector<int>max_col(m);

        for(int i=0;i<n;i++){
            int mn = 100001;
            for(int j=0;j<m;j++){
                mn = min(mn,matrix[i][j]);
            }
            min_row[i]=mn;
        }

        for(int j=0;j<m;j++){
            int mx = -1;
            for(int i=0;i<n;i++){
                mx = max(mx,matrix[i][j]);
            }
            max_col[j]=mx;
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==min_row[i] and matrix[i][j]==max_col[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};