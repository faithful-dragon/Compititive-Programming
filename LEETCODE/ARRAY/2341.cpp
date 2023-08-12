#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n=nums.size(),m=0;
        map<int,int>mp;
        for(int x:nums)mp[x]++;
        for(auto a:mp){
            m+=(a.second)/2;
        }
        return {m,n-2*m};
    }
};