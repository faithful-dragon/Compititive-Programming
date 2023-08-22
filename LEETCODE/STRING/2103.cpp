#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


class rod{
    public:
        bool R=false;
        bool B=false;
        bool G=false;
};

class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length();
        int m = 10;
        cout<<rings<<endl;
        rod rods[m+1];
        for(int i=0;i<n;i+=2){
            char c = rings[i];
            int p = rings[i+1]-'0';
            if(c=='R')rods[p].R=true;
            if(c=='B')rods[p].B=true;
            if(c=='G')rods[p].G=true;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            rod x = rods[i];
            if((x.R) and (x.G) and (x.B)) ans++;
        }
        return ans;
    }
};