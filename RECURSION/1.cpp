#include <iostream>
using namespace std;


void print_name(string name, int n){
    if(n==0)return;
    print_name(name,n-1);
    cout<<n<<" "<<name<<endl;
}

int main(){
    string name;
    cout<<"enter name : ";
    getline(cin,name);
    int n;
    cout<<"n : ";
    cin>>n;
    print_name(name,n);
    return 0;
}