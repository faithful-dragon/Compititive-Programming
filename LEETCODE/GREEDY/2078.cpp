#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int a=0,b=0;
        for(int i=0;i<colors.size();i++){
            for(int j=i;j<colors.size();j++){
                if(colors[i]!=colors[j]){
                    b = abs(i-j);
                    a=max(a,b);
                }
            }
        }
        return a;
    }
};