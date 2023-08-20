#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cost=0;
        for(int pos:position){
            if(pos%2!=0)cost++;
        }
        return min(cost,((int)position.size()-cost));
    }
};