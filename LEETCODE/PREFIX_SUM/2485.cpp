#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int a=0;
        map<int,int>m;
        for(int i=1;i<=n;i++){
            a+=i;
            cout<<i<<" "<<a<<endl;
            m[i]=a;
        }

        a=0;
        cout<<endl;
        for(int i=n;i>=1;i--){
            a+=i;
            cout<<i<<" "<<a<<endl;
            if(m[i]==a)return i;
        }
        return -1;
    }
};