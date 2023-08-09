#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_len=0;
        for(string s:sentences){
            int space=0;
            for(char c:s){
                if(c==' ')space++;
            }
            max_len=max(max_len,space);
        }
        return max_len+1;
    }
};