#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rev(string &s){
        reverse(s.begin(),s.end());
    }
    string finalString(string s) {
        string ans;
        for(char c:s){
            if(c=='i')rev(ans);
            else ans.push_back(c);
        }
        return ans;
    }
};