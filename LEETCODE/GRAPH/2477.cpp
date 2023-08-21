#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    long long f=0;
    int dfs(int v, int p, vector<vector<int>>&g,int &s){
        long long r=1;
        for(int c:g[v]){
            if(c!=p)
                r += dfs(c,v,g,s);
        }
        if(v!=0){
            f+=ceil((double)r/s);
        }
        return r;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1,m=0;
        vector<vector<int>>v(n);
        for(auto x:roads){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }

        long long r = dfs(0,-1,v,seats);
        return f;
    }
};