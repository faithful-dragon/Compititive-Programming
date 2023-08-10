#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char>mp;
        mp[' ']=' ';
        char ch='a';
        for(char c:key){
            if(mp[c] || c==' ')continue;
            else mp[c]=ch++;
        }

        for(int i=0;i<message.length();i++){
            message[i]=mp[message[i]];
        }
        return message;
    }
};