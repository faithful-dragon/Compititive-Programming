#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void subset(int i, int n, vector<int>nums, int xr, int &ans){
        if(i==n){
            ans+=xr;
            return;
        }
        
        xr= xr^nums[i];
        subset(i+1, n, nums, xr, ans);
        xr=xr^nums[i];
        subset(i+1, n, nums, xr, ans);
    }

    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        subset(0,nums.size(),nums,0,ans);
        return ans;
    }
};

