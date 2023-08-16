#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        
        int n=cost.size();
        if(n==1)return cost[0];
        int i=n-1;
        int sum=0;
        while(i>=2)
        {
            sum+=cost[i]+cost[i-1];
            i-=3;
        }
        while(i>=0)
        {
            sum+=cost[i];
            i--;
        }
        return sum;
    }
};