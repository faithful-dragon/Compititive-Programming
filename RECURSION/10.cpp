#include <iostream>
using namespace std;

bool found=false;
void subsequence(int *arr, int i, int n, vector<int>sq, int sum){
    if(i==n){
        if(sum==0){
            for(int i=0;i<sq.size();i++)cout<<sq[i]<<" ";
            if(sq.size()==0)cout<<"{}";
            cout<<endl;
            found=true;
        }
        return;
    }

    if(found==false){
        sq.push_back(arr[i]);
        sum-=arr[i];
        subsequence(arr,i+1,n,sq,sum);

        sq.pop_back();
        sum+=arr[i];
        subsequence(arr,i+1,n,sq,sum);
    }
    else return;
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
    cout<<"required one sequences : "<<endl;
    subsequence(arr,0,n,sq,sum);
    if(found==false)cout<<"not found any..!!"<<endl;
    return 0;
}