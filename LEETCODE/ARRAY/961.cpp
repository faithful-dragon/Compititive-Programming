#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,bool>m;
        for(int x:nums){
            if(m[x])return x;
            else m[x]=true;
        }
        return -1;
    }
};