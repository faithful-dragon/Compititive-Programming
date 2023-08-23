#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>m;
        vector<int>v;
        vector<vector<int>>ans;
        for(int x:nums)m[x]++;
        while(true){
            bool empty=1;
            for(auto p:m){
                if(p.second>0){
                    cout<<p.first<<" "<<p.second<<endl;
                    v.push_back(p.first);
                    m[p.first]--;
                    empty=0;
                }
            }
            if(empty)break;
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};