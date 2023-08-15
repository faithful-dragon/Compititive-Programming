#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>o,e;
        int i=0;
        while(i<nums.size()){
            e.push_back(nums[i]);
            i++;
            if(i==nums.size())break;
            o.push_back(nums[i]);
            i++;
        }
        sort(o.begin(),o.end());
        reverse(o.begin(),o.end());
        sort(e.begin(),e.end());

        i=0;
        int j=0;
        while(i<nums.size()){
            nums[i++]=e[j];
            if(i==nums.size())break;
            nums[i++]=o[j];
            j++;
        }
        return nums;
    }
};