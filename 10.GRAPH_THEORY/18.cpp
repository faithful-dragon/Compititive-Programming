// no of islands

// 5 8
// 1 1 0 0 1 1 0 0
// 1 0 0 1 0 0 0 0
// 0 1 0 1 0 1 1 0
// 1 0 1 0 0 0 1 1
// 0 0 0 1 1 0 0 1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_valid(int i, int j, int n, int m){
    if(i<0 || i>=n)return false;
    if(j<0 || j>=m)return false;
    return true;
}

void dfs(int i, int j, int n, int m, int **land, vector<vector<bool>>&vis){
    if(is_valid(i,j,n,m)==false)return;
    if(vis[i][j]==true)return;
    if(land[i][j]==0)return;

    vis[i][j]=true;
    dfs(i+1,j,n,m,land,vis);
    dfs(i-1,j,n,m,land,vis);
    dfs(i,j+1,n,m,land,vis);
    dfs(i,j-1,n,m,land,vis);

}

int main(){
    int n,m;
    cin>>n>>m;

    int **land = new int*[n];
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        land[i] = new int[m];
        for(int j=0;j<m;j++){
            cin>>land[i][j];
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false and land[i][j]==1){
                cnt++;
                dfs(i,j,n,m,land,vis);
            }
        }
    }
    cout<<"no of island : "<<cnt<<endl;
}
