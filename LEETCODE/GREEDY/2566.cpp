#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> v2,v1;
        while(num){
            v1.push_back(num%10);
            num /= 10;
        }
        reverse(v1.begin(),v1.end());
        v2 = v1;
        int x = 0, y = 0,a=v1[0],b=-1;
        for(int i = 0; i < v1.size(); i++){
            if(b==-1&&v1[i]!=9)b = v1[i];
            if(v1[i]==b)v1[i] = 9;
            if(v2[i]==a)v2[i] = 0;
            x = x*10+v1[i];
            y = y*10+v2[i];
        }
        cout<<x<<" "<<y;
        return x-y;
    }
};