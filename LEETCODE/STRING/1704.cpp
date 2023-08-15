#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    bool vowel(char c){
        if((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u'))return true;
        else if((c=='A') || (c=='E') || (c=='I') || (c=='O') || (c=='U'))return true;
        else return false;
    }
    bool halvesAreAlike(string s) {
        int cnt=0;
        for(int i=0;i<s.length()/2;i++){
            if(vowel(s[i]))cnt++;
        }
        for(int i=s.length()/2;i<s.length();i++){
            if(vowel(s[i]))cnt--;
        }
        return cnt==0;
    }
};