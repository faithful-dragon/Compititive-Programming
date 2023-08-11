#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int el_sum=0,d_sum=0;
        for(int x:nums){
            el_sum+=x;
            while(x>0){
                d_sum+=x%10;
                x=x/10;
            }
        }
        return abs(el_sum-d_sum);
    }
};