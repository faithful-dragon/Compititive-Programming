#include <iostream>
#include <vector>
using namespace std;

// tc = O(sqrt(N))

bool is_prime(int n){
    if(n==1)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    int t;
    cout<<"no of test case : ";
    cin>>t;
    while(t--){
        cout<<"enter no : ";
        int n;
        cin>>n;
        bool isPrime = is_prime(n);
        if(isPrime)cout<<n<<" is a prime number"<<endl;
        else cout<<n<<" is not a prime number"<<endl;
    }
}