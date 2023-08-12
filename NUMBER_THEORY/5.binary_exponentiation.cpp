#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// tc = O(log(N))

int bin_exp(int b, int p){
    int res=1;
    while(p>0){
        if(p%2){
            res = res*b;
            p--;
        }
        else{
            b=b*b;
            p=p/2;
        }
    }
    return res;
}

int main(){
    int t;
    cout<<"no of test case : ";
    cin>>t;
    while(t--){
        cout<<"enter no : ";
        int b,p;
        cin>>b>>p;
        cout<<b<<"^"<<p<<" = "<<bin_exp(b,p)<<endl;
    }
    return 0;
}