// dfs on unconnected grapgh

// 12 8
// 0 1 0 3 0 5 1 2 3 4 3 6 7 8 9 10

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> bfs(int i, int n,vector<bool>&vis,vector<int>v[]){
    queue<int>q;
    q.push(i);
    vis[i]=true;
    vector<int>a;

    while(q.empty()==false){
        int p = q.front();
        q.pop();
        a.push_back(p);

        for(int i=0;i<v[p].size();i++){
            if(vis[v[p][i]]==true)continue;
            q.push(v[p][i]);
            vis[v[p][i]]=true;
        }
    }
    return a;
}

int main(){
    int n,e;
    cout<<"no of node : ";
    cin>>n;
    cout<<"no of edge : ";
    cin>>e;

    vector<int>list[n];

    // adding edges
    int start, end;
    for(int i=0;i<e;i++){
        cout<<"egde "<<i<<" : ";
        cin>>start>>end;
        list[start].push_back(end);
        list[end].push_back(start);
    }

    cout<<"dfs"<<endl;
    vector<bool>vis(n,false);
    vector<vector<int>>data;
    vector<int>v;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            v=bfs(i,n,vis,list);
            data.push_back(v);
        }
    }
    for(auto a:data){
        for(int b:a)cout<<b<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}