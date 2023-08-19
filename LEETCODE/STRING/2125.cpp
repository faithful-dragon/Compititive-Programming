#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int x=0,ans=0;
        for(int i=0;i<bank[0].length();i++){
            if(bank[0][i]=='1')x++;
        }
        for(int i=1;i<bank.size();i++){
            int y=0;
            for(char c:bank[i]){
                if(c=='1')y++;
            }
            ans+=x*y;
            if(y!=0)x=y;
        }
        return ans;
    }
};