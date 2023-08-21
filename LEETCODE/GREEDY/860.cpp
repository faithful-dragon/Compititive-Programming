#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a5=0,a10=0,a20=0;
        for(int x:bills){
            if(x==5)a5++;
            else if(x==10){
                if(a5==0)return false;
                a5--;
                a10++;
            }
            else{
                if(a10>0){
                    a10--;
                    if(a5==0)return false;
                    a5--;
                    a20++;
                }
                else{
                    if(a5<3)return false;
                    a5-=3;
                    a20++;
                }
            }
        }
        return true;
    }
};