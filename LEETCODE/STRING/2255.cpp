#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans=0;
        for(string a:words){
            if(a[0]==s[0]){
                int i=0;
                int j=0;
                while(a[i]==s[j]){
                    i++;
                    j++;
                    if(i==a.length()){
                        ans++;
                        break;
                    }
                    if(j==s.length())break;
                }
            }
        }
        return ans;
    }
};