#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int bar_cnt=0,star=0;
        for(char c:s){
            if(c=='|')bar_cnt++;
            else if(bar_cnt%2==0 and c=='*')star++;
        }
        return star;
    }
};