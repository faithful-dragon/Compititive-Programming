// update color

// 3 3
// 1 1 1
// 1 1 0
// 1 0 1
// 1 1 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_valid(int i, int j, int n, int m){
    if(i<0 || i>=n)return false;
    if(j<0 || j>=m)return false;
    return true;
}

void paint(int i, int j, int oc,int nc, int n, int m, vector<vector<int>>&grid, vector<vector<bool>>&vis){
    if(is_valid(i,j,n,m)==false)return;
    if(vis[i][j]==true)return;
    if(grid[i][j]==nc)return;

    if(grid[i][j]==oc){
        vis[i][j]=true;
        grid[i][j] =nc;
        paint(i+1,j,oc,nc,n,m,grid,vis);
        paint(i-1,j,oc,nc,n,m,grid,vis);
        paint(i,j+1,oc,nc,n,m,grid,vis);
        paint(i,j-1,oc,nc,n,m,grid,vis);
    }

}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>grid(n,vector<int>(m,0));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int cnt=0;
    int sr,sc,nc;
    cin>>sr>>sc>>nc;
    int oc = grid[sr][sc];   // old color
    paint(sr,sc,oc,nc,n,m,grid,vis);
    cout<<endl<<"updated grid "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
