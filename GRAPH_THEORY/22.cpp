// cycle in directed graph
#include <iostream>
#include <vector>
using namespace std;

bool check_cycle(int p, vector<bool>vis, vector<int>v[]){
    vis[p]=true;
    for(int c:v[p]){
        if(vis[c]=true and c==p)continue;
        else if(vis[c]==true)return true;
        else return check_cycle(c,vis,v);
    }
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

    for(int i=0;i<v;i++){
        vector<bool>vis(v,false);
        if(check_cycle(i,vis,g)){
            cout<<"cyclic"<<endl;
            return;
        }
    }

    cout<<"no cycle found"<<endl;
}