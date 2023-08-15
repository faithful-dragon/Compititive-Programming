// dfs of weighted graph

// 7 6
// 0 1 0 0 3 2 0 5 4 1 2 5 3 4 9 3 6 4

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void dfs(int per, vector<bool>&vis, vector<pair<int,int>>v[]){
    vis[per]=true;
    cout<<"per = "<<per<<endl;
    for(pair<int,int> child:v[per]){
        cout<<"per : "<<per<<", child : "<<child.first<<", weight : "<<child.second<<endl;
        if(vis[child.first]){
            cout<<"return"<<endl;
            continue;
        }
        dfs(child.first,vis,v);
    }
}

int main(){
    int n,e;
    cout<<"no of node : ";
    cin>>n;
    cout<<"no of edge : ";
    cin>>e;

    vector<pair<int,int>>list[n];

    // adding edges
    int start, end, weight;
    for(int i=0;i<e;i++){
        cout<<"egde "<<i<<" : ";
        cin>>start>>end>>weight;
        list[start].push_back({end,weight});
        list[end].push_back({start,weight});
    }

    // dfs
    cout<<endl;
    vector<bool>vis(n,false);
    dfs(0,vis,list);
    return 0;
}