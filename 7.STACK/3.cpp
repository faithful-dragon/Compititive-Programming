// valid paranthesis
#include <iostream>
#include <stack>
using namespace std;

//Function to check if brackets are balanced or not.
bool ispar(string x){
    // Your code here
    stack<char>st,s;
    for(char c:x){
        if(c=='[' or c=='(' or c=='{')st.push(c);
        else if(st.empty()==true)return false;
        else if(c==']'){
            if(st.top()!='[')return false;
            else st.pop();
        }
        else if(c=='}'){
            if(st.top()!='{')return false;
            else st.pop();
        }
        else if(c==')'){
            if(st.top()!='(')return false;
            else st.pop();
        }
        
        cout<<"stack : ";
        s=st;
        while(s.empty()==false){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    return st.empty()==true;
}

int main(){
    string a;
    cin>>a;
    if(ispar(a))cout<<"balanced"<<endl;
    else cout<<"not balanced"<<endl;
}