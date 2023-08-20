#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=nums.size()-1;i>=1;i-=2){
            ans+=min(nums[i],nums[i-1]);
        }
        return ans;
    }
};