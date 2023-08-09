#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        int cnt;
        for(int x:nums){
            cnt=0;
            for(int y:nums){
                if(x>y)cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};