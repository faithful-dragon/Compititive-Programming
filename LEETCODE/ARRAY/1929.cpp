#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans(2*nums.size());
        int i=0;
        for(int x:nums){
            ans[i]=x;
            ans[i+nums.size()]=x;
            i++;
        }
        return ans;
    }
};