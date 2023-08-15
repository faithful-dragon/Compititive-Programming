#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        double ans=0.00000;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int x = (5*n)/100;
        cout<<n<<" "<<x<<endl;
        for(int i=x;i<n-x;i++){
            ans+=1.0*arr[i];
        }
        return ans/(n-2*x);
    }
};