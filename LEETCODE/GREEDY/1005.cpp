#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(k==0)break;
            if(nums[i]<0){
                nums[i]*=-1;
                k--;
            }
        }
        sort(nums.begin(),nums.end());
        k = k%2;
        if(k)nums[0]*=-1;
        int y=0;
        for(int x:nums)y+=x;
        return y;
    }
};