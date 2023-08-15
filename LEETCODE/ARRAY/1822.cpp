#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        for(int x:nums){
            if(x==0)return 0;
            else if(x<0)neg++;
        }
        if(neg%2)return -1;
        else return 1;
    }
};