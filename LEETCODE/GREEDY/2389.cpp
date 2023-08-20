#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int sum=0, i=0,n=nums.size();
        vector<int>ans;
        int size=0;
        for(int s:queries){
            size=0;
            sum=0;
            for(int x:nums){
                sum+=x;
                size++;
                if(sum>s){
                    size--;
                    break;
                }
            }
            ans.push_back(size);
        }
        return ans;
    }
};