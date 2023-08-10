#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char start_x, start_y, end_x, end_y;
        start_x=s[0];
        start_y=s[1];
        end_x=s[3];
        end_y=s[4];
        int sy=start_y;
        vector<string>ans;
        while(start_x != end_x || start_y != end_y){
            string a;
            a.push_back(start_x);
            a.push_back(start_y);
            ans.push_back(a);
            if(start_y <end_y)start_y++;
            else{
                start_y=sy;
                start_x++;
            }
        }
        string a;
        a.push_back(start_x);
        a.push_back(start_y);
        ans.push_back(a);
        return ans;
    }
};