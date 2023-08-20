#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        vector<int>v;
        while(num>0){
            v.push_back(num%10);
            num=num/10;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int a=0,b=0,j=0;
        for(int i=0;i<v.size();i+=2){
            a+=pow(10,j)*v[i];
            j++;
        }
        cout<<a<<endl;
        j=0;
        for(int i=1;i<v.size();i+=2){
            b+=pow(10,j)*v[i];
            j++;
        }
        cout<<b<<endl;
        return a+b;
    }
};