#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        map<string,char>mp;
        char ch='a';
        int i=1;
        for(int i=1;i<=26;i++){
            if(i<10){
                mp[to_string(i)]=ch++;
            }
            else{
                mp[to_string(i)+"#"]=ch++;
            }
        }

        for(auto a:mp)cout<<a.first<<" "<<a.second<<endl;

        string a="",ans;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='#'){
                a+=s[i];
                i--;
                a+=s[i];
                i--;
                a+=s[i];
                reverse(a.begin(),a.end());
                ans.push_back(mp[a]);
                a="";
            }
            else{
                string b="";
                b+=s[i];
                ans.push_back(mp[b]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};