#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// tc = O(sqrt(N)))

int mx = 1000000;
vector<int>is_prime(mx,-1);
void seive(){
    for(int i=2;i*i<=mx;i++){
        if(is_prime[i]==-1){
            for(int j=i;j<=mx;j+=i){
                if(is_prime[j]==-1){
                    is_prime[j]=i;
                }
            }
        }
    }
}

void prime_factorization(int n){
    while(is_prime[n]!=-1){
        cout<<is_prime[n]<<" ";
        n=n/is_prime[n];
    }
    cout<<endl;
}

int main(){
    seive();
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