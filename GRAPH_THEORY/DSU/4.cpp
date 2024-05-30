// detect cycle in undirected graph
#include <iostream>
#include <vector>
#include<set>
using namespace std;

class DisjointSet{
    private:
    vector<int>rank;
    vector<int>size;
    vector<int>parent;

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int n){   // find ultimate parent
        if(n == parent[n])
            return n;
        else return parent[n]=findUPar(parent[n]);
    }

    void unionByRank(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu==pv)return;

        if(rank[pu]<rank[pv])
            parent[pu]=pv;
        else if(rank[pv]<rank[pu])
            parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    void print_rank(){
        cout<<"rank : ";
        for(int x:rank)
            cout<<x<<" ";
        cout<<endl;
    }

    void print_parents(){
        cout<<"par  : ";
        for(int x:parent)
            cout<<x<<" ";
        cout<<endl;
    }
};

int main(){
    DisjointSet dsu(5);
    if(dsu.findUPar(1)==dsu.findUPar(3))cout<<"loop"<<endl;
    dsu.unionByRank(1,3);
    if(dsu.findUPar(3)==dsu.findUPar(0))cout<<"loop"<<endl;
    dsu.unionByRank(3,0);
    if(dsu.findUPar(0)==dsu.findUPar(4))cout<<"loop"<<endl;
    dsu.unionByRank(0,4);
    if(dsu.findUPar(0)==dsu.findUPar(2))cout<<"loop"<<endl;
    dsu.unionByRank(0,2);
    if(dsu.findUPar(2)==dsu.findUPar(4))cout<<"loop"<<endl;
    dsu.unionByRank(2,4);
}


class DisjointSet{
    private:
    vector<int>rank;
    vector<int>size;
    vector<int>parent;

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int n){   // find ultimate parent
        if(n == parent[n])
            return n;
        else return parent[n]=findUPar(parent[n]);
    }

    void unionByRank(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu==pv)return;

        if(rank[pu]<rank[pv])
            parent[pu]=pv;
        else if(rank[pv]<rank[pu])
            parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[]){
	    // Code here
	    set<pair<int,int>>s;
	    pair<int,int>p;
	    
	    for(int i=0;i<V;i++){
	        for(int j:adj[i]){
	            p = {min(i,j),max(i,j)};
	            s.insert(p);
	        }
	    }
	    
	    DisjointSet dsu(V);
	    for(pair<int,int>p:s){
	        int i=p.first;
	        int j=p.second;
            if(dsu.findUPar(i)==dsu.findUPar(j))return 1;
            else dsu.unionByRank(i,j);
	    }
	    return 0;
	}
};