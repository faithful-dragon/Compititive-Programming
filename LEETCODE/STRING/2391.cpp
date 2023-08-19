#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        int cost=0;
        int i=-1, j=-1,k=0, l=-1;
        for(string s:garbage){
            ans+=s.length();
            for(char c:s){
                if(c=='G')i=k;
                if(c=='P') j=k;
                if(c=='M') l=k;
            }
            k++;
            if(k<travel.size())travel[k]+=travel[k-1];
        }
        for(int c:travel)cout<<c<<" ";cout<<endl;
        if(i>0)ans+=travel[i-1];
        if(j>0)ans+=travel[j-1];
        if(l>0)ans+=travel[l-1];
        return ans;
    }
};