#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int>ans;
        int j=0;
        for(int i:index)ans.insert(ans.begin()+i,nums[j++]);
        return ans;
    }
};