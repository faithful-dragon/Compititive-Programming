#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(string s:operations){
            if(s.front()=='-' or s.back()=='-')x--;
            else x++;
        }
        return x;
    }
};