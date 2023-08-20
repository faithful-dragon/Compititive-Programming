#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int ans=word.length(),x=0;
        for(char c:word){
            int y = c-'a';
            ans+=min(abs(x-y),(26-abs(x-y)));
            x=y;
        }
        return ans;
    }
};