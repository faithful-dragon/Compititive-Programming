// no of connected components in a matrix

// 5 6
// 1 0 1 1 1 0
// 0 1 1 0 0 0
// 1 0 0 1 0 1
// 1 0 1 0 0 0
// 1 0 1 1 0 1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_valid(int i, int j, int n, int m){
    if(i<0 || i>=n)return false;
    if(j<0 || j>=m)return false;
    return true;
}

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int i, int j, int n, int m, int **mat){
    if(is_valid(i,j,n,m)==false)return;
    if(mat[i][j]==0)return;

    mat[i][j]=0;
    for(int k=0;k<4;k++){
        dfs(i+dx[k], j+dy[k], n, m, mat);
    }
}

int main(){
    int n,m;
    cout<<"enter value of n,m :";
    cin>>n>>m;

    // allocate memory for matrix
    int **mat = new int*[n];
    for(int i=0;i<n;i++){
        mat[i] = new int[m];
    }

    // fill matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    // use dfs
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                cnt++;
                dfs(i,j,n,m,mat);
            }
        }
    }
    cout<<"no of compnents are : "<<cnt<<endl;
    return 0;
}