#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<int, vector<int>, greater<int>>v;
        for(int k=0;k<n;k++){
            int j=0;
            int i=k;
            while(i<n and j<m){
                v.push(mat[i][j]);
                i++;
                j++;
            }
            j=0;
            i=k;
            while(i<n and j<m){
                mat[i][j] = v.top();
                i++;
                j++;
                v.pop();
            }
        }

        for(int k=1;k<m;k++){
            int j=k;
            int i=0;
            while(i<n and j<m){
                v.push(mat[i][j]);
                i++;
                j++;
            }
            j=k;
            i=0;
            int l=0;
            while(i<n and j<m){
                mat[i][j] = v.top();
                i++;
                j++;
                v.pop();
            }
        }
        return mat;
    }
};