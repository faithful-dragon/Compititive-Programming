// segment tree for sum in array
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5+1;
int arr[N], tree[4*N];

void build(int node, int st, int end){
    if(st == end){
        tree[node] = arr[st];
        return;
    }

    int mid = st + (end-st)/2;
    build(2*node, st, mid);
    build(2*node +1 , mid+1, end);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node, int st, int end, int l, int r){
    if(r<st or l>end)return 0;
    if(st>=l and end<=r)return tree[node];

    int mid = (st + end)/2;
    int a = query(2*node, st, mid, l, r);
    int b = query(2*node + 1, mid+1, end, l, r);
    return a+b;
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(1,0,n-1);
    for(int i=1;i<n;i++)cout<<tree[i]<<" ";
    cout<<endl; 

    while(true){
        int type;
        cin>>type;
        if(type == -1)break;
        if(type == 1){
            int l, r;
            cin>>l>>r;
            cout<<"sum = "<<query(1,0,n-1,l,r)<<endl;
        }
    }
}
