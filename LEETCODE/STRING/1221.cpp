#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int r=0,l=0;
        for(char c:s){
            if(c=='R')r++;
            else l++;
            if(l==r)ans++;
        }
        return ans;
    }
};