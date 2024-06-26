// sential_linear_search
#include <iostream>
using namespace std;


// no of comparisions are N + 2
int sential_linear_search(int arr[], int n, int key){
    int last = arr[n-1];
    arr[n-1]=key;

    int i=0;
    while(arr[i]!=key) i++;   // no of comparision : N

    arr[n-1]=last;
    if(i<(n-1) or arr[n-1]==key)return i;   // no of comparision : 2
    else return -1;
}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int idx;
    int key = 9;
    idx = sential_linear_search(a,10,key);
    if(idx == -1)cout<<"Not found"<<endl;
    else cout<<"Found at index "<<idx<<endl;

    key=0;
    idx = sential_linear_search(a,10,key);
    if(idx == -1)cout<<"Not found"<<endl;
    else cout<<"Found at index "<<idx<<endl;
}
