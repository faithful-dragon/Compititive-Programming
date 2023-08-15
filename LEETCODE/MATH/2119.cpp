#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num%10==0 and num!=0)return false;
        return true;
    }
};