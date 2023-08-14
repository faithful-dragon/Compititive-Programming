#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a;
        a = (int)coordinates[0] + coordinates[1]-'0';
        return a%2;
    }
};