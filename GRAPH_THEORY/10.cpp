// bfs of graph

// 7 6
// 0 1 0 3 0 5 1 2 3 4 3 6

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int i, int n,vector<int>v[]){
    queue<int>q;
    q.push(i);
    vector<bool>vis(n,false);
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

    // bfs
    vector<int>bfss;
    bfss = bfs(0,n,list);
    for(int i=0;i<bfss.size();i++){
        cout<<bfss[i]<<" ";
    }
    cout<<endl;

    return 0;
}