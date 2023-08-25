#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;



class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        vector<int>v=nums;
        for(int i=0;i<l.size();i++){
            v=nums;
            int x = l[i];
            int y = r[i];
            int d;
            sort(v.begin()+x, v.begin()+y+1);
            bool f = 1;
            if(x==y)d=0;
            else d = v[y] - v[y-1];
            
            for(int j=x+1;j<=y;j++){
                if((v[j]-v[j-1]) != d){
                    f=0;
                    break;
                }
            }
            if(f)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};