#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_money=0;
        for(vector<int>bank:accounts){
            int total_money=0;
            for(int money:bank){
                total_money+=money;
            }
            max_money = max(max_money,total_money);
        }
        return max_money;
    }
};