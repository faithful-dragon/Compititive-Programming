#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt=0;
        for(vector<string>v:items){
            if(ruleKey=="type"){
                if(v[0]==ruleValue)cnt++;
            }
            else if(ruleKey=="color"){
                if(v[1]==ruleValue)cnt++;
            }
            else if(ruleKey=="name"){
                if(v[2]==ruleValue)cnt++;
            }
        }
        return cnt;
    }
};