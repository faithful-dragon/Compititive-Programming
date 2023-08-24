#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int x:nums){
            if(x>0)pos.push_back(x);
            else neg.push_back(x);
        }
        nums.clear();
        for(int i=0;i<pos.size();i++){
            nums.push_back(pos[i]);
            nums.push_back(neg[i]);
        }
        return nums;
    }
};