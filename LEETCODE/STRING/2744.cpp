#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        map<string,int>m;
        for(string s:words){
            string a = s;
            reverse(a.begin(),a.end());
            m[s]++;
            if(a!=s)m[a]++;
        }
        int ans=0;
        for(auto a:m){
            ans+=a.second/2;
        }
        return ans/2;
    }
};