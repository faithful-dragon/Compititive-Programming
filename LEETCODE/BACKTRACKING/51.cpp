#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>>ans;

    // void print(vector<string>v){
    //     for(string s:v){
    //         for(char c:s)cout<<c<<" ";
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    bool valid(int r, int c, int n, vector<string>chess){
        for(int i=0;i<n;i++){
            if(chess[r][i]=='Q')return false;
            if(chess[i][c]=='Q')return false;
        }

        int x=r;
        int y=c;
        while(x>=0 and y>=0){
            if(chess[x][y]=='Q')return false;
            x--;
            y--;
        }

        x=r;
        y=c;
        while(x<n and y>=0){
            if(chess[x][y]=='Q')return false;
            x++;
            y--;
        }

        return true;
    }

    void queen(int col, int n, vector<string>chess){
        //print(chess);
        if(col == n){
            ans.push_back(chess);
            return;
        }

        for(int row=0;row<n;row++){
            if(valid(row,col,n,chess)){
                chess[row][col]='Q';
                queen(col+1,n,chess);
                chess[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0;i<n;i++)s.push_back('.');
        vector<string>chess(n,s);
        queen(0,n,chess);
        return ans;
    }
};

