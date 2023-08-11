#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0,i=0,j=0;
        while(true){
            ans+=mat[i][j];
            i++;
            j++;
            if(i==n and j==m)break;
        }
        i=0;
        j=m-1;
        while(true){
            ans+=mat[i][j];
            i++;
            j--;
            if(i==n and j==-1)break;
        }
        if(n%2==1)ans-=mat[n/2][n/2];
        return ans;
    }
};