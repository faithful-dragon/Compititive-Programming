#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) 
    {
        unordered_set<int> s(suits.begin() , suits.end());
        if(s.size() == 1)   return "Flush";
        sort(ranks.begin() , ranks.end());
        int mx = 0, count = 1;
        for(int i = 1; i < 5; i++)
        {
            if(ranks[i] == ranks[i - 1])
            {
                count++;
                mx = max(count , mx);
            }
            else
                count = 1;
        }
        if(mx >= 3)  return "Three of a Kind";
        if(mx == 2)  return "Pair";
        return "High Card";
    }
};