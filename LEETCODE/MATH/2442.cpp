#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<string>st;
        for(int x:nums){
            string s = to_string(x);
            st.insert(s);
            while(s.back()=='0')s.pop_back();
            reverse(s.begin(),s.end());
            st.insert(s);
        }
        return st.size();
    }
};