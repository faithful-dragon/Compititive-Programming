#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<=2)return -1;
        else{
            sort(nums.begin(),nums.end());
            return nums[1];
        }
    }
};