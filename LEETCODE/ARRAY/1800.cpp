#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int a=nums[0],b=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                a+=nums[i];
            }
            else{
                b=max(a,b);
                a=nums[i];
            }
        }
        return max(a,b);
    }
};