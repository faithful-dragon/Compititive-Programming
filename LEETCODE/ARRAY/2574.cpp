#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>right_sum(nums.size(),0),left_sum(nums.size(),0),ans;
        for(int i=1;i<nums.size();i++){
            left_sum[i] =  nums[i-1] + left_sum[i-1];
        }
        
        for(int i=nums.size()-2;i>=0;i--){
            right_sum[i] =  nums[i+1] + right_sum[i+1];
        }
        for(int i=0;i<nums.size();i++)ans.push_back(abs(right_sum[i]-left_sum[i]));
        return ans;
    }
};