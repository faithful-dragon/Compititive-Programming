#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,y=0;
        for(int x:gain){
            y+=x;
            ans=max(ans,y);
        }
        return ans;
    }
};