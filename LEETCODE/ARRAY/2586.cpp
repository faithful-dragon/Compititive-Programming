#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool is_vowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        else return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            string s = words[i];
            ans+= (is_vowel(s.front()) and is_vowel(s.back()));
        }
        return ans;
    }
};
