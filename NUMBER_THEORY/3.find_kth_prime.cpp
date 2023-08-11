#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// tc = O(Nlog(Log(N)))
// 1 : prime
// 0 : composite

int mx = 9000000;
vector<bool>is_prime(mx,true);
vector<int>prime;
void seive(){
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2;i*i<=mx;i++){
        if(is_prime[i]==1){
            for(int j=i*i;j<=mx;j+=i){
                is_prime[j]=false;
            }
        }
    }

    for(int i=0;i<mx;i++){
        if(is_prime[i]==true){
            prime.push_back(i);
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
        cout<<n<<"th prime number is : "<<prime[n-1]<<endl;
    }
}