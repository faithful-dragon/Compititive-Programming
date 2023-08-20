#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i=0;i<s.length();i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }

        int j=0;
        num=0;
        for(int i=s.length()-1;i>=0;i--){
            int x = s[i]-'0';
            num+=pow(10,j)*x;
            j++;
        }
        return num;
    }
};