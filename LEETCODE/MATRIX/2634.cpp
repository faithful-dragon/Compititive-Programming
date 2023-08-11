#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int pos1=0,pos2=0;
        int cnt1=0,cnt2=0;
        for(vector<int>v:mat){
            for(int x:v){
                cnt1+=x;
            }
            if(cnt2<cnt1){
                cnt2=cnt1;
                pos2=pos1;
            }
            pos1++;
            cnt1=0;
        }
        return {pos2,cnt2};
    }
};