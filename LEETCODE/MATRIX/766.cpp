#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int j=0;j<m;j++){
            int k=j,i=0;
            int a=matrix[i][j];
            while(i<n and k<m){
                if(matrix[i][k]!=a)return false;
                i++;
                k++;
            }
        }

        for(int i=0;i<n;i++){
            int k=i,j=0;
            int a=matrix[k][j];
            while(k<n and j<m){
                if(matrix[k][j]!=a)return false;
                j++;
                k++;
            }
        }

        return true;

    }
};