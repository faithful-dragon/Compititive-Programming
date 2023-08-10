#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,bool>m;
        for(char c:jewels)m[c]=true;
        int ans=0;
        for(char c:stones)if(m[c])ans++;
        return ans;
    }
};