#include <iostream>
using namespace std;

void subsequence(int *arr, int i, int n, vector<int>sq){
    if(i==n){
        for(int i=0;i<sq.size();i++)cout<<sq[i]<<" ";
        if(sq.size()==0)cout<<"{}";
        cout<<endl;
        return;
    }

    sq.push_back(arr[i]);
    subsequence(arr,i+1,n,sq);

    sq.pop_back();
    subsequence(arr,i+1,n,sq);

}

int main(){
    int n;
    cout<<"n : ";
    cin>>n;

    cout<<"enter n elements : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int>sq;
    cout<<"sequences are : "<<endl;
    subsequence(arr,0,n,sq);
    return 0;
}