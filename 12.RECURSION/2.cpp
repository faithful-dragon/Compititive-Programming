#include <iostream>
using namespace std;


void print_n_2_1(int n){
    cout<<n<<" ";
    if(n==1)return;
    print_n_2_1(n-1);
}

int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    print_n_2_1(n);
    cout<<endl;
    return 0;
}