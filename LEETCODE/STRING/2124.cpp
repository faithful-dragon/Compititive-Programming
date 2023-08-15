#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int b=101;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b')b=i;
            else if(i>b)return false;
        }
        return true;
    }
};