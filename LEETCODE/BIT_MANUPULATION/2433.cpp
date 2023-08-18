#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x = 0;
        vector<int>ans;
        for(int y:pref){
            ans.push_back(x^y);
            x = y;
        }
        return ans;
    }
};
