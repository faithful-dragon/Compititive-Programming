#include <iostream>
using namespace std;

// tc = O(2^n)


int fibonacci(int n){
    if(n<=1)return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    cout<<" n = ";
    cin>>n;
    cout<<n<<"th fibonacci number is : "<<fibonacci(n)<<endl;
    return 0;
}