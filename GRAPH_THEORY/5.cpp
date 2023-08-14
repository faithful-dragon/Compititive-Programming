// adjacency list for undirected unweighted graph

// 7 6
// 0 1 0 3 0 5 1 2 3 4 3 6

#include <iostream>
#include <vector>
using namespace std;

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

    // printing list
    cout<<endl;
    cout<<"adjacency list : "<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        for(int j=0;j<list[i].size();j++)cout<<list[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}