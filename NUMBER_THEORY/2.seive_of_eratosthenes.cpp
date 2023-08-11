#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// tc = O(Nlog(Log(N)))
// 1 : prime
// 0 : composite

int mx = 1000000;
vector<bool>is_prime(mx,1);
void seive(){
    is_prime[0]=0;
    is_prime[1]=0;
    for(int i=2;i*i<=mx;i++){
        if(is_prime[i]==1){
            for(int j=i*i;j<=mx;j+=i){
                is_prime[j]=0;
            }
        }
    }
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
        if(is_prime[n])cout<<n<<" is a prime number"<<endl;
        else cout<<n<<" is not a prime number"<<endl;
    }
}