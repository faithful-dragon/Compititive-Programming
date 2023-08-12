#include <iostream>
using namespace std;

void print_1_2_n(int n){
    if(n==0)return;
    print_1_2_n(n-1);
     cout<<n<<" ";
}

int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    print_1_2_n(n);
    cout<<endl;
    return 0;
}