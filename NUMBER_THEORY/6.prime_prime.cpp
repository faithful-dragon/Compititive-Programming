#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mx = 9000000;
vector<bool>is_prime(mx,1);
vector<int>pp(mx,0);
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
    int cnt=0;
    for(int i=1;i<mx;i++){
        if(is_prime[i]==true){
            cnt++;
        }
        if(is_prime[cnt]==true){
            pp[i]=1;
        }
    }

    for(int i=1;i<mx;i++){
        pp[i]+=pp[i-1];
    }
}

int main(){
    seive();
    for(int i=1;i<20;i++)cout<<pp[i]<<" ";
    cout<<endl;
    int t;
    cout<<"no of test case : ";
    cin>>t;
    while(t--){
        cout<<"enter l and r : ";
        int l,r;
        cin>>l>>r;
        int no_of_pp = pp[r]-pp[l-1];
        cout<<"no of pp between "<<l<<" and "<<r<<" = "<<no_of_pp<<endl;
    }
    return 0;
}