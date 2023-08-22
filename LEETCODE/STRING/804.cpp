#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char,string>m;
        vector<string>v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        char ch='a';
        for(string s:v){
            m[ch]=s;
            ch++;
        }
        set<string>st;
        string s1="";
        for(string s:words){
            for(char c:s){
                s1+=(m[c]);
            }
            st.insert(s1);
            s1="";
        }
        for(string s:st)cout<<s<<endl;
        return st.size();
    }
};