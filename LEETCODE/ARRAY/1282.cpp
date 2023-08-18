#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<int>v;
        vector<vector<int>>ans;
        map<int,vector<int>>m;

        for(int i=0;i<groupSizes.size();i++){
            m[groupSizes[i]].push_back(i);
        }

        for(auto a:m){
            int s = a.first;
            int l = a.second.size();
            int t = l/s;
            while(t>0){
                while(v.size()!=s){
                    v.push_back(a.second.back());
                    a.second.pop_back();
                }
                ans.push_back(v);
                v.clear();
                t--;
            }
        }
        return ans;
    }
};