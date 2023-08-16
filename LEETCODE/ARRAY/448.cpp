#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        map<int,bool>m;
        for(int i=1;i<=nums.size();i++)m[i]=false;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }
        for(int i=1;i<=nums.size();i++){
            if(m[i]==false)ans.push_back(i);
        }
        return ans;
    }
};