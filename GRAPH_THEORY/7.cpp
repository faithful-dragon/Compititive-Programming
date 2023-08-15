// adjacency list for undirected weighted graph

// 7 6
// 0 1 0 0 3 2 0 5 4 1 2 5 3 4 9 3 6 4

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,e;
    cout<<"no of node : ";
    cin>>n;
    cout<<"no of edge : ";
    cin>>e;

    vector<pair<int,int> >list[n];

    // adding edges
    int start, end, weight;
    pair<int,int>p;
    for(int i=0;i<e;i++){
        cout<<"egde "<<i<<" : ";
        cin>>start>>end>>weight;
        p.first=end;
        p.second=weight;
        list[start].push_back(p);
        p.first=start;
        list[end].push_back(p);
    }

    // printing list
    cout<<endl;
    cout<<"adjacency list : "<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        for(int j=0;j<list[i].size();j++)cout<<list[i][j].first<<"->"<<list[i][j].second<<"   ";
        cout<<endl;
    }

    return 0;
}