// adjacency matrix for directed unweighted graph

// 7 6
// 0 1 0 3 0 5 1 2 3 4 3 6

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,e;
    cout<<"no of node : ";
    cin>>n;
    cout<<"no of edge : ";
    cin>>e;

    int **mat = new int*[n];
    for(int i=0;i<n;i++){
        mat[i] = new int[n];
    }

    // intialize matrix with 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }

    // adding edges
    int start, end;
    for(int i=0;i<e;i++){
        cout<<"egde "<<i<<" : ";
        cin>>start>>end;
        mat[start][end]=1;
    }

    // printing list
    cout<<endl;
    cout<<"adjacency matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}