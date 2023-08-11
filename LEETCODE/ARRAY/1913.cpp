#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return (nums.back()*nums[nums.size()-2] - nums[0]*nums[1]);
    }
};