#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ans;
        for(string s:words){
            string a;
            for(char c:s){
                if(c==separator and a.length()>0){
                    ans.push_back(a);
                    a.clear();
                }
                else if(c!=separator) a.push_back(c);
            }
            if(a.length()>0){
                ans.push_back(a);
            }
            a.clear();
        }
        return ans;
    }
};