#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        int row = startPos[0];
        int col = startPos[1];
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            count = 0;
            row = startPos[0];
            col = startPos[1];
            for(int j = i; j < s.size(); j++)
                if(s[j] == 'R')
                    if(col < n - 1){
                        count++;
                        col++;
                    }
                    else break;
                else if(s[j] == 'L')
                    if(col > 0){                        
                        count++;
                        col--;
                    }
                    else break;
                else if(s[j] == 'D')
                    if(row < n - 1){                        
                        count++;
                        row++;
                    }
                    else break;
                else
                    if(row > 0){                        
                        count++;
                        row--;
                    }
                    else break;
            res.push_back(count);
        }
        return res;
    }
};