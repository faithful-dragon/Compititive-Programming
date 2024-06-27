// find sq root
#include <iostream>
#include <vector>
using namespace std;


int find_sqroot(int n){
    int low=1;
    int high=n;
    int mid;
    int ans=1;

    while(low<=high){
        mid = low + (high-low)/2;
        if((mid*mid)<=n){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}

int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    int sr = find_sqroot(n);
    cout<<"square root of "<<n<<" is : "<<sr<<endl;
}