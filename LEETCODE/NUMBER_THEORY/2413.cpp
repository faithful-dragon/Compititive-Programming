#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0)return n;
        else return 2*n;
    }
};