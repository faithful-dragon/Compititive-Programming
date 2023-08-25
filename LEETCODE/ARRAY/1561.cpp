#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;



class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int x=0;
        for(int y:piles)cout<<y<<" ";cout<<endl;
        int i = piles.size()-2, n = piles.size()/3;
        while(n--){
            x+= piles[i];
            i-=2;
        }
        return x;
    }
};