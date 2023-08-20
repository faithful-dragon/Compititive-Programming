#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int x=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                x+= abs(nums[i]-nums[i-1])+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return x;
    }
};