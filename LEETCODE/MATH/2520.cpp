#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int n=num,cnt=0;
        while(num>0){
            int a = num%10;
            if(n%a==0)cnt++;
            num = num/10;
        }
        return cnt;
    }
};