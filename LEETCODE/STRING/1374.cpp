#include <iostream>
#include <math.h>
#include <map>
using namespace std;


class Solution {
public:
    string generateTheString(int n) {
        string a;
        if(n%2){
            while(n--)a.push_back('a');
        }
        else{
            n--;
            a.push_back('a');
            while(n--)a.push_back('b');
        }
        return a;
    }
};