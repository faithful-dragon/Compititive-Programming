#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int max_candies=0;
        for(int candy:candies){
            if(max_candies < candy)max_candies = candy;
        }
        for(int candy:candies){
            if((candy+extraCandies)>=max_candies)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};