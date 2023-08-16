#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>ind1(n+1,0);
        vector<int>ind2(n+1,0);
        for(vector<int>v:trust){
            ind1[v[0]]++;
            ind2[v[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(ind1[i]==0 and ind2[i]==n-1)return i;
        }
        return -1;
    }
};