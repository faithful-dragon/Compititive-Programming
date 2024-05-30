// no of connected components using DSU
#include <iostream>
#include <vector>
using namespace std;

class DSU{
    private:
    vector<int>rank;
    vector<int>par;

    public:
    DSU(int n){
        rank.resize(n+1,0);
        par.resize(n+1);

        for(int i=0;i<=n;i++)
            par[i]=i;
    }

    int FindUPar(int v){
        if(v==par[v])return v;
        else return par[v] = FindUPar(par[v]); 
    }

    void Union(int u, int v){
        int pu = FindUPar(u);
        int pv = FindUPar(v);

        if(pu==pv)return;

        if(rank[pu]<rank[pv]){
            par[pv]=pu;
        }
        else{
            par[pv]=pu;
            rank[pv]++;
        }
    }

    bool isConnected(int u, int v){
        if(FindUPar(u)==FindUPar(v))return true;
        else return false;
    }
};


int main(){
    int n,e;
    cin>>n>>e;

    DSU ds(n);

    // adding edges
    int start, end;
    for(int i=0;i<e;i++){
        cin>>start>>end;
        ds.Union(start,end);
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(ds.FindUPar(i)==i){
            cout<<i<<endl;
            cnt++;
        }
    }
    cout<<"ans = "<<cnt<<endl;

    return 0;
}