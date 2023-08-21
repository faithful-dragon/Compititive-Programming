#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,vector<int>>m;
        vector<int>ind(n,0);
        for(auto a:roads){
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
            ind[a[0]]++;
            ind[a[1]]++;
        }
        
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mx<(ind[i] + ind[j])){
                    mx = ind[i] + ind[j];
                    for(int x:m[i]){
                        if(x==j){
                            mx--;
                            break;
                        }
                    }
                }
            }
        }
        return mx;
    }
};