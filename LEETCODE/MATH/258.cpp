#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        
        if(num==0)return 0;
        while((int)log10(num)>0){
            int n = num;
            int x=0;
            while(n>0){
                int a = n%10;
                x = x + a;
                n=n/10;
            }
            num=x;
        }
        return num;
    }
};