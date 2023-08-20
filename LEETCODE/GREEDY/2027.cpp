#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int minimumMoves(string s) {
		int n = s.size();
		int ans = 0;
		for(int i=0;i<n;i++){
			if(s[i] == 'X'){
				ans++;
				i+=2;
			}
		}
		return ans;
	}
};

