#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,bool>mp;
        char ch='a';
        do{
            mp[ch++]=false;
        }while(ch!='z');
        mp['z']=false;
        for(char c:sentence){
            mp[c]=true;
        }
        for(auto a:mp){
            if(a.second==false)return false;
        }
        return true;
    }
};
