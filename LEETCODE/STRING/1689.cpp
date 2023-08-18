#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int x=0;
        for(char c:n){
            x = max(x,(c-'0'));
        }
        return x;
    }
};