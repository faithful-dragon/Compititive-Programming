// no of connected components in graph

// 11 8
// 0 1 0 3 0 5 1 2 3 4 3 6 7 8 9 10

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void dfs(int per, vector<bool>&vis, vector<int>v[]){
    vis[per]=true;
    cout<<per<<" ";
    for(int child:v[per]){
        if(vis[child]){
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

    int cnt = 0;
    cout<<endl;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            cnt++;
            cout<<"component "<<cnt<<" : ";
            dfs(i,vis,list);
            cout<<endl;
        }
    }
    cout<<"no of compnents are : "<<cnt<<endl;
    return 0;
}