#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>m;
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            int cnt=0;
            m[A[i]]++;
            for(int j=0;j<=i;j++){
                cnt+=m[B[j]];
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};