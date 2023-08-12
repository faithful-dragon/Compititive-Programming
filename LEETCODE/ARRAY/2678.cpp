#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(string s:details){
            int l=s.length();
            int n = (s[l-4]-'0')*10 + (s[l-3]-'0');
            if(n>60)cnt++;
        }
        return cnt;
    }
};