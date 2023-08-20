#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int sum=0,y=0;
        for(int x:nums)sum+=x;
        for(int i=nums.size()-1;i>=0;i--){
            y+=nums[i];
            ans.push_back(nums[i]);
            if(2*y>sum)break;
        }
        return ans;
    }
};