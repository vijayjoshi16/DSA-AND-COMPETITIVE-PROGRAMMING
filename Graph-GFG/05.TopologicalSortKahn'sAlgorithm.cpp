#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        ans.push_back(tmp);
        for(int i=0;i<adj[tmp].size();i++){
            indegree[adj[tmp][i]]--;
            if(indegree[adj[tmp][i]]==0)
            q.push(adj[tmp][i]);
        }
    }
    return ans;
}
