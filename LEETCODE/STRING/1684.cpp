#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        map<char,bool>m;
        for(char c:allowed)
            m[c]=true;
        for(string s:words){
            bool na=1;
            for(char c:s){
                if(m[c]==false){
                    na=0;
                    break;
                }
            }
            if(na==1)cnt++;
        }
        return cnt;
    }
};