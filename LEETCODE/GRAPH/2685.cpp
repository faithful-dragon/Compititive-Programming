#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:

    void dfs(int p, vector<int>&a, vector<bool>&vis, vector<vector<int>>v){
        for(int c:v[p]){
            if(vis[c]==false){
                vis[c]=true;
                a.push_back(c);
                dfs(c,a,vis,v);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v(n);
        vector<int>ind(n,0);
        for(auto a:edges){
            v[a[0]].push_back(a[1]);
            v[a[1]].push_back(a[0]);
            ind[a[0]]++;
            ind[a[1]]++;
        }

        int cnt=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                vis[i]=true;
                vector<int>a;
                a.push_back(i);
                dfs(i,a,vis,v);
                int d = a.size()-1;
                bool cc = true;
                for(int x:a){
                    if(ind[x]!=d){
                        cc=false;
                        break;
                    }
                }
                if(cc) cnt++;
            }
        }
        return cnt;
    }
};