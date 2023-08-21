#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt=0;
        int a1 = max(a,b);
        int b1 = min(a,b);
        for(int i=1;i<=a1/2;i++){
            if(a1%i==0 and b1%i==0){
                cnt++;
            }
        }
        if(a==b)cnt++;
        return cnt;
    }
};