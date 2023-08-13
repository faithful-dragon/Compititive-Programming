#include <iostream>
using namespace std;

int subsequence(int *arr, int i, int n, vector<int>sq, int sum){
    if(i==n){
        if(sum==0) return 1;
        else return 0;
    }
    sq.push_back(arr[i]);
    sum-=arr[i];
    int take_cnt = subsequence(arr,i+1,n,sq,sum);

    sq.pop_back();
    sum+=arr[i];
    int not_take_cnt = subsequence(arr,i+1,n,sq,sum);
    return take_cnt + not_take_cnt;
}

int main(){
    int n,sum;
    cout<<"n : ";
    cin>>n;

    cout<<"enter n elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<"req sum : ";
    cin>>sum;

    vector<int>sq;
    int cnt = subsequence(arr,0,n,sq,sum);
    cout<<"no of seq with req sum = "<<cnt<<endl;
    return 0;
}