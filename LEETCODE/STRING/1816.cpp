#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        for(char c:s){
            if(c==' ')k--;
            if(k==0)break;
            ans.push_back(c);
        }
        return ans;
    }
};