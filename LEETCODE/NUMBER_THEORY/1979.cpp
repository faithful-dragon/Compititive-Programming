#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:

    int gcd(int x, int y){
        if(y==0)return x;
        return gcd(y,x%y);
    }
    int findGCD(vector<int>& nums) {
        int mx=INT_MIN;
        int mn=INT_MAX;

        for(int x:nums){
            mx=max(mx,x);
            mn=min(mn,x);
        }

        return gcd(mx,mn);
    }
};