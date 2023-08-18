#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        for(int i=0;i<boxes.size();i++){
            int x=0;
            for(int j=0;j<boxes.size();j++){
                if(boxes[j]=='1'){
                    x+=abs(i-j);
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};