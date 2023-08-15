#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(string s:patterns){
            bool f=0;
            for(int j=0;j<word.length();j++){
                int i=0;
                if(s[i]==word[j]){
                    int k=j;
                    while(s[i]==word[k]){
                        i++;
                        k++;
                        if(i==s.length()){
                            cnt++;
                            f=1;
                            break;
                        }
                        if(k==word.length())break;
                    }
                }
                if(f)break;
            }
        }
        return cnt;
    }
};