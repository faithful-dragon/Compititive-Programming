#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++){
            if(int(s[i])<=90 and (s[i])>=65)s[i]=s[i]+32;
        }
        return s;
    }
};
