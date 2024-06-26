// cycle in directed graph
#include <iostream>
#include <vector>
using namespace std;

void fun(vector<bool>v){
    for(bool b:v)cout<<b<<" ";
    cout<<endl;
}

bool check_cycle(int p, vector<bool>&vis, vector<bool>path,vector<int>v[]){
    cout<<"node : "<<p<<endl;
    vis[p]=true;
    path[p]=true;
    fun(vis);
    fun(path);
    cout<<endl;
    for(int c:v[p]){
        if(vis[p]==false){
            if(check_cycle(c,vis,path,v))return true;
        }
        else if(path[c]==true)return true;
    }

    path[p]=false;
    return false;
}

int main(){
    int n,v;
    cin>>n>>v;

    vector<int>g[n];
    int s,e;
    for(int i=0;i<v;i++){
        cin>>s>>e;
        g[s].push_back(e);
    }

    cout<<"graph"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(int x:g[i])cout<<x<<" ";
        cout<<endl;
    }

    vector<bool>vis(n,false);
    vector<bool>path(n,false);

    for(int i=0;i<n;i++){
        cout<<i<<endl;
        if(vis[i]==false){
            if(check_cycle(i,vis,path,g)){
                cout<<"cyclic"<<endl;
                return 0;
            }
        }
        cout<<endl;
    }
    cout<<"no cycle found"<<endl;
}

/*
     |'''''|
2 -> 0  -> 1 -> 3
            ^   |
            |___|
*/