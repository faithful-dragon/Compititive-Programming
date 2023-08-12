#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx=arr.back();
        vector<int>ans;
        ans.push_back(-1);
        for(int i=arr.size()-2;i>=0;i--){
            mx = max(mx,arr[i+1]);
            ans.push_back(mx);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};