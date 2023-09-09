// max sum of subsequence with no adj element in a cicular array

// 3
// 2 3 2
// 4
// 1 3 2 1

#include <iostream>
#include <vector>
using namespace std;


//space optimization
// TC = O(N)
// SC = O(2)
int max_sum3(vector<int>num){
    int prev1 = num[0];
    int prev2 = 0;
    for(int i=1;i<num.size();i++){
        int pick = num[i];
        if(i>1)pick+=prev2;
        int not_pick = 0 + prev1;
        prev2 = prev1;
        prev1 = max(pick, not_pick);
    }
    return prev1;
}


int main(){
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++)
        cin>>num[i];
    vector<int>a,b;
    for(int i=0;i<n;i++){
        if(i!=0)a.push_back(num[i]);
        if(i!=n-1)b.push_back(num[i]);
    }

    int ans1 = max_sum3(a);
    int ans2 = max_sum3(b);
    int ans = max(ans1, ans2);
    cout<<"ans = "<<ans<<endl;
    return 0;
}
