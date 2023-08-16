#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans,ind(n);
        for(auto a:edges){
            ind[a[1]]++;
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0)ans.push_back(i);
        }
        return ans;
    }
};