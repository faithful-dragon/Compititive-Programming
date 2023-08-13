#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)return true;
        else if(n%2!=0 || n==0)return false;
        else return isPowerOfTwo(n/2);
    }
};