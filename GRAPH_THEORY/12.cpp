// dfs of unweighted graph

// 7 6
// 0 1 0 3 0 5 1 2 3 4 3 6

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void dfs(int per, vector<bool>&vis, vector<int>v[]){
    vis[per]=true;
    cout<<"per = "<<per<<endl;
    for(int child:v[per]){
        cout<<"per : "<<per<<", child : "<<child<<endl;
        if(vis[child]){
            cout<<"return"<<endl;
            continue;
        }
        dfs(child,vis,v);
    }
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

    // dfs
    cout<<endl;
    vector<bool>vis(n,false);
    dfs(0,vis,list);
    return 0;
}