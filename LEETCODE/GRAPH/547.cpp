#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:

    void dfs(int p, vector<bool>&vis, vector<vector<int>>v){
        for(int c:v[p]){
            if(vis[c]==false){
                vis[c]=true;
                dfs(c,vis,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& x) {
        int cnt =0;
        vector<vector<int>>v(x.size());
        for(int i=0;i<x.size();i++){
            for(int j=0;j<x.size();j++){
                if(x[i][j]==1)v[i].push_back(j);
            }
        }

        vector<bool>vis(x.size(),false);
        for(int i=0;i<x.size();i++){
            if(vis[i]==false){
                cnt++;
                vis[i]=true;
                dfs(i,vis,v);
            }
        }
        return cnt;
    }
};