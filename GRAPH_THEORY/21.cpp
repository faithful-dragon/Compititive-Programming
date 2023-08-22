// rotten oranges

// 3 3
// 2 1 1
// 0 1 1
// 1 0 1

// 3 3
// 2 1 1
// 0 1 1
// 1 1 1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_valid(int i, int j, int n, int m){
    if(i<0 || i>=n)return false;
    if(j<0 || j>=m)return false;
    return true;
}
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>>q;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
                vis[i][j]=true;
            }
        }
    }
    q.push({-1,-1});
    int time=0;
    
    while(q.empty()==false){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x==-1 and y==-1){
            time++;
            if(q.empty()==false)
                q.push({-1,-1});
            for(auto a:grid){
                for(int b:a)cout<<b<<" ";
                cout<<endl;
            }
            cout<<endl;
        }
        else{
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(is_valid(nx,ny,n,m) == false)continue;
                if(grid[nx][ny]==0)continue;
                if(vis[nx][ny]==true)continue;

                vis[nx][ny] = true;
                q.push({nx,ny});
                grid[nx][ny]=2;
            }
        }
    }
    for(auto a:grid){
        for(int b:a)
        if(b==1)return -1;
    }
    return time-1;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int time;
    time = orangesRotting(grid);
    cout<<"time = "<<time<<endl;
    return 0;
}
