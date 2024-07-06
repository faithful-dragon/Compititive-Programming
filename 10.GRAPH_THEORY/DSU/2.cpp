// no of connected components using DSU
#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int weight;
    int start;
    int end;

    node(int a, int b, int c){
        weight = a;
        start = b;
        end = c;
    }
};

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

    int noOfconnectedComponent(){
        int ans = 0;
        for(int i=1;i<=par.size();i++){
            if(par[i]==i)ans++;
        }
        return ans;
    }
};

// sum of weight of spanning tree
int spanningTree(vector<node *>v, int n){
    int w = 0;
    DSU ds2(n);
    for(node* n:v){
        cout<<n->weight<<" "<<n->start<<" "<<n->end<<endl;
        if(ds2.FindUPar(n->start) == ds2.FindUPar(n->end))continue;
        else{
            ds2.Union(n->start,n->end);
            w+=n->weight;
        }
    }
    return w;
}

static bool cmp(node *a, node *b){
    return a->weight<b->weight;
}

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

    int noc = 0;
    noc = ds.noOfconnectedComponent();
    cout<<"no of componenet : "<<noc<<endl;

    cout<<"enter details for graph 2 "<<endl;
    cin>>n>>e;
    vector<node *>edge;
    for(int i=0;i<e;i++){
        int s,e,w;
        cin>>s>>e>>w;
        node *n1 = new node(w,s,e);
        edge.push_back(n1);
    }

    sort(edge.begin(),edge.end(),cmp);

    int minweight = spanningTree(edge,n);
    cout<<"weight : "<<minweight<<endl;

    return 0;
}


// 7 6 1 2 2 3 4 5 6 7 5 6 3 7
// 6 9 5 4 9 5 1 4 4 1 1 4 3 5 4 2 3 1 2 2 3 2 3 3 6 8 2 6 7