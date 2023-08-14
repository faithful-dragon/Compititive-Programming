#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int minimumSum(int n) {
        vector<int>v;
        while(n>0){
            v.push_back(n%10);
            n=n/10;
        }
        sort(v.begin(),v.end());
        int a = v[0]*10 + v[3];
        int b = v[1]*10 + v[2];
        cout<<a<<" "<<b<<endl;
        return a+b;
    }
};