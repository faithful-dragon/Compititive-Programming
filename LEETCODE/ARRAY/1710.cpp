#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:

    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        sort(bt.begin(),bt.end(), cmp);
        int ans = 0;
        for(vector<int>v:bt){
            int x = min(v[0],ts);
            int y = v[1];
            ans += x*y;
            ts = max(0,ts-v[0]);
        }
        return ans;
    }
};