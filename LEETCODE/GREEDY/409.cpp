#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>mp;
        for(char c:s)mp[c]++;
        int x=0;
        bool odd=0;
        for(auto a:mp){
            if(a.second%2==0)x+=a.second;
            else{
                odd=1;
                x+=a.second-1;
            }
        }
        if(odd)x++;
        return x;
    }
};