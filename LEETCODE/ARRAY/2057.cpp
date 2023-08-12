#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int i=0;
        for(int x:nums){
            if((i%10)==x)return i;
            i++;
        }
        return -1;
    }
};