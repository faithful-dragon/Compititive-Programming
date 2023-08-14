// seperate node from each level

// 7 6
// 0 1 0 3 0 5 1 2 3 4 3 6

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > bfs(int i, int n,vector<int>v[]){
    queue<int>q;
    q.push(i);
    q.push(-1);
    vector<bool>vis(n,false);
    vis[i]=true;
    vector<int>a;
    vector<vector<int> >ans;
    while(q.empty()==false){
        int p = q.front();
        q.pop();

        if(p==-1){
            if(q.empty()==false){
                q.push(-1);
            }
            ans.push_back(a);
            a.clear();
        }
        else{
            a.push_back(p);
            for(int i=0;i<v[p].size();i++){
                if(vis[v[p][i]]==true)continue;
                q.push(v[p][i]);
                vis[v[p][i]]=true;
            }
        }        
    }
    return ans;
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
    vector<vector<int> >ans;
    ans = bfs(0,n,list);
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}