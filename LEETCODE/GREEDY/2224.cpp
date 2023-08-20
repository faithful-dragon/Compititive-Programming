#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int c2i(char c){
        return c-'0';
    }
    int fun(string s){
        int x=0;
        x = (10*c2i(s[0]) + c2i(s[1]))*60 +  10*c2i(s[3]) + c2i(s[4]);
        return x;
    }
    int convertTime(string current, string correct) {
        int x = fun(current);
        int y = fun(correct);
        int d = abs(y-x);
        int times=0;
        if(d>=60){
            times += d/60;
            d=d%60;
        }
        if(d>=15){
            times += d/15;
            d=d%15;
        }
        if(d>=5){
            times += d/5;
            d=d%5;
        }
        return times+d;
    }
};