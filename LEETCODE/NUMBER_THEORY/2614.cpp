#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    
    void seive(int n, vector<bool>&prime){
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<n;j+=i)
                    prime[j]=false;
            }
        }
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = 4000001,ans=0;
        vector<bool>prime(n,true);
        seive(n,prime);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if((i==j) || (i+j==nums.size()-1)){
                    if(prime[nums[i][j]])
                        ans = max(ans,nums[i][j]);
                }
            }
        }

        return ans;
    }
};