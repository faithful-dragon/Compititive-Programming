#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// tc = O(sqrt(N)))

void prime_factorization(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            cout<<i<<"^"<<cnt<<" ";
        }
    }
    if(n>1)cout<<n<<"^"<<1<<" ";
    cout<<endl;
}

int main(){
    int t;
    cout<<"no of test case : ";
    cin>>t;
    while(t--){
        cout<<"enter no : ";
        int n;
        cin>>n;
        cout<<"prime factorization of "<<n<<" : ";
        prime_factorization(n);
    }
}