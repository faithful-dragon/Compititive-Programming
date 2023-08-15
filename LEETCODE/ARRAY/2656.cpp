#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx=0,ans=0;
        for(int x:nums)mx=max(mx,x);
        while(k--){
            ans+=mx;
            mx++;
        }
        return ans;
    }
};