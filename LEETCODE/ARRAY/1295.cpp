#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int x:nums){
            if(((int)(log10(x)))%2==1)cnt++;
        }
        return cnt;
    }
};