// Connecting the graph
#include <iostream>
#include <vector>
using namespace std;


class DisjointSet {
    public:
        vector<int> rank, parent;
        
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            
            for(int i=0; i<=n; i++) {
                parent[i] = i;
            }
        }
        
        int findUParent(int node) {
            if(parent[node] == node)
                return node;
            
            return parent[node] = findUParent(parent[node]);
        }
        
        void unionByRank(int u, int v) {
            int ul_parent_u = findUParent(u);
            int ul_parent_v = findUParent(v);
            
            if(ul_parent_u == ul_parent_v)
                return;
            
            if(rank[ul_parent_u] < rank[ul_parent_v]) {
                parent[ul_parent_u] = ul_parent_v;
            }
            else if(rank[ul_parent_v] < rank[ul_parent_u]) {
                parent[ul_parent_v] = ul_parent_u;
            }
            else {
                parent[ul_parent_v] = ul_parent_u;
                rank[ul_parent_u]++;
            }
        }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        
        int cntExtra = 0;
        for(auto it: edge) {
            int  u = it[0];
            int  v = it[1];
            
            if(ds.findUParent(u) == ds.findUParent(v))
                cntExtra++;
            else
                ds.unionByRank(u, v);
        }
        
        int connectedComp = 0;
        for(int i=0; i<n; i++) {
            if(ds.parent[i] == i)
                connectedComp++;
        }
        
        int ans = connectedComp-1;
        if(cntExtra >= ans)
            return ans;
        
        return -1;
    }
};