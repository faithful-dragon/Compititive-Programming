#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    string removeTrailingZeros(string num) {
        while(num.back()=='0')num.pop_back();
        return num;
    }
};