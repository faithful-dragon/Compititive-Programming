// linear search
#include <iostream>
using namespace std;

// total comparision : 2N
int linear_search(int arr[], int n, int key){
    for(int i=0;i<n;i++){    // no of comparision : n
        if(arr[i]==key)return i;   // no of comparision : n
    }
    return -1;
}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int idx;
    int key = 9;
    idx = linear_search(a,10,key);
    if(idx == -1)cout<<"Not found"<<endl;
    else cout<<"Found at index "<<idx<<endl;

    key=0;
    idx = linear_search(a,10,key);
    if(idx == -1)cout<<"Not found"<<endl;
    else cout<<"Found at index "<<idx<<endl;
}
