#include <iostream>
#include <vector>
using namespace std;

string toLower(string s) {
    for(int i=0;i<s.length();i++){
        if((int)s[i] < 91)s[i]+=32;
    }
    return s;
}

string to_upper(string s){
    for(int i=0;i<s.length();i++){
        if((int)s[i] > 91)s[i]-=32;
    }
    return s;
}

vector <int> count (string s){
    int small=0;
    int big=0;
    int num=0;
    int special=0;
    for(char c:s){
        int pos = (int)c;
        if(pos>64 and pos<91)big++;
        else if(pos>96 and pos<123)small++;
        else if(c=='0' or c=='1' or c=='2' or c=='3' or c=='4' or c=='5' or c=='6' or c=='7' or c=='8' or c=='9')num++;
        else special++;
    }
    return {big,small,num,special};
}


bool vower(char c){
    if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return true;
    return false;
}