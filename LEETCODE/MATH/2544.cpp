#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int y=0;
        bool f=1;
        vector<int>v;
        while(n%10==0)n=n/10;
        while(n>0){
            v.push_back(n%10);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        for(int x:v){
            if(f){
                f=0;
                y+=x;
            }
            else{
                f=1;
                y-=x;
            }
        }
        return y;
    }
};