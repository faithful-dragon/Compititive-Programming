#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int distMoney(int m, int n) {
        if(m < n){
            return -1;
        }
        m -= n;
        if(m<7)return 0;
        if(m==n*7)return n;
        if(m<=7*(n-1)+2)return  m/7;
        m-= 7*(n-1);
        if(m==3)return n-2;
        return n-1;
    }
};