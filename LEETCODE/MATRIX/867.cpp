#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>ans;
        vector<int>v;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                v.push_back(matrix[i][j]);
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};