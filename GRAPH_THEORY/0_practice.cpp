// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     int v,e;
//     cin>>v>>e;
    
//     int arr[v][v];
//     vector<int>g[v];
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             arr[i][j]=0;
//         }
//     }
//     int a,b,w=1;
//     for(int i=0;i<e;i++){
//         cin>>a>>b;
//         arr[a][b]=w;
//         arr[b][a]=w;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     cout<<"adj matrix"<<endl;
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;

//     cout<<"adj list"<<endl;
//     for(int i=0;i<v;i++){
//         cout<<i<<" ->";
//         for(int x:g[i])cout<<x<<" ";
//         cout<<endl;
//     }

//     vector<int>t_g[v];
//     for(int i=0;i<v;i++){
//         for(int x:g[i])
//     }

//     int **mat = new int*[v];
//     for(int i=0;i<v;i++){
//         mat[i] = new int[v];
//     }

    


// }





#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

// Function to perform Depth First Search (DFS) to check if there's a path between two switches
bool canCommunicate(vector<vector<int>>& switches, vector<bool>& visited, int source, int destination) {

    cout<<"Node: "<<source<<endl;
 
    // Mark the current switch as visited
    visited[source] = true;

    // If source switch is same as destination, return true
    if (source == destination) return true;


    // Check all switches connected to the current switch
    for (int i = 0; i < switches[source].size(); ++i) {
        int connectedSwitch = switches[source][i];

        //cout<<connectedSwitch<<endl;

        // If the connected switch is not visited, perform DFS
        if (!visited[connectedSwitch]) {
            if (canCommunicate(switches, visited, connectedSwitch, destination)) {
                return true;
            }
        }
    }

    // If no path found
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q; // Number of switches, users, and queries

        // Initialize switches adjacency list and map
        vector<vector<int>> switches(n +1);
        vector<string>ans;
        map<int,int>mp;
        for(int i=0;i<=m;i++)mp[i]=-1;


        // Process each connection
        for (int i = 0; i < q; ++i) {
            int type, a, b;
            cin >> type >> a >> b;
            if (type == 0) {
                // If type 0, connect switches a and b
                switches[a].push_back(b);
                switches[b].push_back(a);
            } 
            else if (type == 1) {
                mp[a]=b;
            }
            else{
                
                cout<<endl;
                cout<<"connections : "<<endl;
                for(int i=0;i<=n;i++){
                    if(switches[i].size()!=0){
                        cout<<i<<" -> ";
                        for(int x:switches[i])cout<<x<<" ";
                        cout<<endl;
                    }
                }
                cout<<endl;


                if(a==b){
                    ans.push_back("YES");
                    break;
                }
                else if(mp[a]==-1 or mp[b]==-1){
                    ans.push_back("NO");
                    break;
                }
                else{
                    // If type 2, check if user a can communicate with user b
                    vector<bool> visited(n + 1, false);
                    if (canCommunicate(switches, visited, mp[a], mp[b])) {
                        ans.push_back("YES");
                    } else {
                        ans.push_back("NO");
                    }
                }
            }
        }

        for(string a:ans){
            cout<<a<<endl;
        }
        ans.clear();
    }


    return 0;
}

