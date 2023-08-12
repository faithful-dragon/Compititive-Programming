#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        for(int i=n/2;i>0;i--)ans.push_back(-i);
        if(n%2==1)ans.push_back(0);
        for(int i=n/2;i>0;i--)ans.push_back(i);
        return ans;
    }
};