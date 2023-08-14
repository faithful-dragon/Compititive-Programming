#include <iostream>
#include <math.h>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            int j = i;
            bool f=0;
            while(j>0){
                int k = j%10;
                if(k==0 || i%k!=0){
                    f=1;
                    break;
                }
                j=j/10;
            }
            if(f==0)ans.push_back(i);
        }
        return ans;
    }
};