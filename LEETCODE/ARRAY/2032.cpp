#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>ans;
        set<int>s;
        map<int,int>mp1,mp2,mp3;
        for(int x:nums1)mp1[x]++;
        for(int x:nums2)mp2[x]++;
        for(int x:nums3)mp3[x]++;

        for(auto x:mp1){
            if(mp2[x.first]>0 or mp3[x.first]>0)s.insert(x.first);
        }
        for(auto x:mp2){
            if(mp3[x.first]>0)s.insert(x.first);
        }
        for(int x:s)ans.push_back(x);
        return ans;
    }
};

