// segment tree for max / min in array
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
    tree[node] = max(tree[2*node],tree[2*node + 1]);
}

int query(int node, int st, int end, int l, int r){
    if(r<st or l>end)return INT_MIN;
    if(st>=l and end<=r)return tree[node];

    int mid = (st + end)/2;
    int a = query(2*node, st, mid, l, r);
    int b = query(2*node + 1, mid+1, end, l, r);
    return max(a,b);
}

void update(int node, int st, int end, int index, int val){
    if(st == end){
        arr[st]=val;
        tree[node]=val;
        return;
    }

    int mid = st + (end-st)/2;
    if(index <= mid)update(2*node, st, mid, index, val);
    else update(2*node+1, mid+1, end, index, val);

    tree[node] = max(tree[2*node], tree[2*node+1]);
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
            cout<<"max = "<<query(1,0,n-1,l,r)<<endl;
        }
        if(type == 2){
            int index, key;
            cin>>index>>key;
            update(1,0,n-1,index, key);
        }
    }
}

// 6 8 -1 2 17 1 3 2 4