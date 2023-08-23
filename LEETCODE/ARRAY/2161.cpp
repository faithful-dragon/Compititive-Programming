#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans,x;
        for(int x:nums){
            if(x==pivot)
            ans.push_back(pivot);
        }

        int i=0,j=nums.size()-1;
        while(i!=nums.size()){
            if(nums[i]>pivot)ans.push_back(nums[i]);
            if(nums[j]<pivot)x.push_back(nums[j]);
            i++;
            j--;
        }
        reverse(x.begin(),x.end());
        for(int y:ans)x.push_back(y);
        return x;
    }
};
