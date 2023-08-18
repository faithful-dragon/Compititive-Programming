#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool is_inside(int a, int b, int x, int y, int r){
        double a1=a,b1=b,x1=x,y1=y,r1=r;
        if( (((a1-x1)*(a1-x1)) + ((b1-y1)*(b1-y1))) <=(r1*r1) )return true;
        else return false;

    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans(queries.size(),0);
        int i=0;
        for(auto q:queries){
            for(vector<int>p:points){
                if(is_inside(p[0],p[1],q[0],q[1],q[2]))ans[i]++;
            }
            i++;
        }
        return ans;
    }   
};