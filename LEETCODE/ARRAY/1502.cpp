#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()<=2)return true;
        sort(arr.begin(),arr.end());
        int d = arr[1]-arr[0];
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]!=d)return false;
        }
        return true;
    }
};