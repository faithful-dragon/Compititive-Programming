#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        int cnt=0;
        map<int,string>mp;
        string a;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                a.pop_back();
                int ind = s[i-1]-'0';
                mp[ind]=a;
                a.clear();
                cnt++;
            }
            else a.push_back(s[i]);
        }
        int ind = a.back()-'0';
        a.pop_back();
        mp[ind]=a;
        a.clear();
        s.clear();
        for(int i=1;i<=cnt+1;i++){
            s+=mp[i];
            s+=" ";
        }
        s.pop_back();
        return s;
    }
};