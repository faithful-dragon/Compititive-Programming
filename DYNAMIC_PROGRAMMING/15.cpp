// divide in two subset with equal sum
// 6
// 2 3 3 3 4 5


#include <iostream>
#include <vector>
using namespace std;


// SPACE OPTIMIZATION
// TC = O(N*T)
// SC = O(K)
bool sub_sum3(int n, int k, vector<int>v){
    vector<bool>prev(k+1,0);
    prev[0]=true;
    if(v[0]<=k)prev[v[0]] = true;

    for(int i=1;i<n;i++){
        vector<bool>curr(k+1,0);
        for(int target=1;target<=k;target++){
            bool pick = false;
            if(v[i]<=target) pick = prev[target-v[i]];
            bool not_pick = prev[target];
            curr[target]= (pick or not_pick);
        }
        prev = curr;
    }
    return prev[k];
}


int main(){
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }

    if(sum%2!=0)cout<<0<<endl;
    else cout<<(sub_sum3(n,sum/2,v))<<endl;;

}