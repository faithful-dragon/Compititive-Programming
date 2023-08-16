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

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size(),false);
        vis[0]=true;
        dfs(0,vis,rooms);
        for(bool f:vis){
            if(f==false)return false;
        }
        return true;
    }
};