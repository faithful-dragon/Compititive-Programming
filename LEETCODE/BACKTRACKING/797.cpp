#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int p, int n, vector<int>v, vector<vector<int>>& graph, vector<bool>vis){
        vis[p]=true;
        if(p==n){
            ans.push_back(v);
            return;
        }
        for(int c:graph[p]){
            if(vis[c]==false){
                vis[c]=true;
                v.push_back(c);
                dfs(c,n,v,graph,vis);
                vis[c]=false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>v;
        vector<bool>vis(graph.size(),false);
        v.push_back(0);
        dfs(0,graph.size()-1,v,graph,vis);
        return ans;
    }
};