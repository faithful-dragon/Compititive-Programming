#include <iostream>
using namespace std;

bool is_pal(string s, int i, int l){
    if(s[i]!=s[l])return false;
    else if(i<=l)return true;
    else return is_pal(s,i+1,l-1);
}

int main(){
    string s;
    cout<<"enter string : ";
    cin>>s;
    if(is_pal(s,0,s.length()-1))cout<<"it is palindrome"<<endl;
    else cout<<"it is not palindrome"<<endl;
    return 0;
}