#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:

    int md(int a, int b, int x, int y){
        return abs(a-x) + abs(b-y);
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int idx=-1;
        int dis = 100001;
        int i=0;
        for(vector<int>point:points){
            if(point[0]==x || point[1]==y){
                int d = md(x,y,point[0],point[1]);
                if(dis>d){
                    dis=d;
                    idx = i;
                }
            }
            i++;
        }
        return idx;
    }
};