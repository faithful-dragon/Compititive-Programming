#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int j=-1;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2){
                j=i;
                break;
            }
        }
        string s;
        int i=0;
        while(i<=j){
            s.push_back(num[i]);
            i++;
        }
        return s;
    }
};