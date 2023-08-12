#include <iostream>
using namespace std;


int print_sum_to_n(int n){
    if(n==0)return 0;
    return n+print_sum_to_n(n-1);
}

int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    int sum = print_sum_to_n(n);
    cout<<sum<<endl;
    return 0;
}