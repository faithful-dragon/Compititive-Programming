#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string s="";
        for(int i=0;i<command.length();i++){
            if(command[i]=='(' and command[i+1]==')'){
                i++;
                s+='o';
            }
            else if(command[i]=='('){
                i++;
                do{
                    s+=command[i];
                    i++;
                }while(command[i]!=')');
            }
            else s+=command[i];
        }
        return s;
    }
};