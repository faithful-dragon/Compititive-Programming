#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:

    vector<vector<int>>ans;
    void per(int i, int n,vector<int>nums){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            per(i+1,n,nums);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        per(0,nums.size(),nums);
        return ans;
    }
};