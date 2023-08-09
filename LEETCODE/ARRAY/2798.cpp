#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans=0;
        for(int x:hours){
            if(x>=target)ans++;
        }
        return ans;
    }
};