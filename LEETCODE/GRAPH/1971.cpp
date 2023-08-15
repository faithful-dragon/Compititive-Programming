#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>v[n];
        for(auto a:edges){
            v[a.front()].push_back(a.back());
            v[a.back()].push_back(a.front());
        }

        vector<bool>vis(n,false);
        queue<int>q;
        q.push(source);
        vis[source]=true;

        while(q.empty()==false){
            int p = q.front();
            q.pop();
            if(p==destination)return true;
            else{
                for(int c:v[p]){
                    if(vis[c]==false){
                        q.push(c);
                        vis[c]=true;
                    }
                }
            }
        }
        return false;
    }
};