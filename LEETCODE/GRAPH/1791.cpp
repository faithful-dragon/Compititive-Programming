#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mp;
        for(int i=0;i<edges.size();i++){
            vector<int>v = edges[i];
            mp[v[0]]++;
            mp[v[1]]++;
        }
        int mn=-1,j=0;;
        for(auto a:mp){
            if(a.second>mn){
                mn=a.second;
                j=a.first;
            }
        }
        return j;
    }
};