#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        map<int,int>mp;
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            mp[i]=s;
        }

        s=0;
        int ans = nums.size();
        bool found = false;
        for(int i=nums.size()-1;i>=0;i--){
            s+=nums[i];
            if(mp[i]==s){
                ans = min(ans,i);
                found = true;
            }
        }
        if(found)return ans;
        return -1;
    }
};