#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        int count=0,iter=1;
        int s[number.size()];
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == digit) 
                count++;
        }
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == digit && iter==count) {
                number.erase(number.begin() + i);
                break;
            }
            else if(number[i] == digit && iter!=count){
                if(number[i+1]>number[i]) {
                        number.erase(number.begin() + i);
                        break;
                    }
                else{
                    iter++;
                    continue;
                }
            }
        }
    return number;
    }
};