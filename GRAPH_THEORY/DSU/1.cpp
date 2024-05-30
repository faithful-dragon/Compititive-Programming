// disjoint

#include <iostream>
#include <vector>
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

    void unionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu==pv)return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    void is_joint(int u, int v){
        if(findUPar(u)==findUPar(v)){
            cout<<u<<" and "<<v<<" have same parents"<<endl;
            return;
        }
        cout<<u<<" and "<<v<<" don't have same parents"<<endl;
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    ds.is_joint(3,7);

    ds.unionByRank(3,7);
    ds.is_joint(3,7);

    cout<<endl;

    DisjointSet ds1(7);
    ds1.unionBySize(1,2);
    ds1.unionBySize(2,3);
    ds1.unionBySize(4,5);
    ds1.unionBySize(6,7);
    ds1.unionBySize(5,6);

    ds1.is_joint(3,7);

    ds1.unionBySize(3,7);
    ds1.is_joint(3,7);

    //cout<<ds1.findUPar(3)<<" "<<ds1.findUPar(7)<<endl;

    return 0;
}