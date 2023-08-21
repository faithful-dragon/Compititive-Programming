#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:

    int gcd(int x, int y){
        if(y==0)return x;
        else return gcd(y,x%y);
    }
    int countBeautifulPairs(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int x = nums[i];
                while(x>9){
                    x = x/10;
                }
                int y = nums[j]%10;
                if(gcd(max(x,y),min(x,y))==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};