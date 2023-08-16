#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];
        int cntmin = 1;
        int cntmax = 1;
        for(int i=1; i<n; i++){
            if(nums[i] < mini){
                mini = nums[i];
                cntmin = 1;
            }
            else if(nums[i] == mini) cntmin++;

            if(nums[i] > maxi){
                maxi = nums[i];
                cntmax = 1;
            }
            else if(nums[i] == maxi) cntmax++;
        }

        if(mini == maxi) return 0;

        return n - (cntmin + cntmax);
    }
};