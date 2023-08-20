#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(nums[i]!=0){
                for(int j=i;j<nums.size();j++){
                    nums[j]-=x;
                }
                cnt++;
            }
            for(int x:nums)cout<<x<<" ";
            cout<<endl;
        }
        return cnt;
    }
};