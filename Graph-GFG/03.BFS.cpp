#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
    vector<int> res;
    bool visited[N];
    list<int> q;
    int s;
    for(int i=0;i<N;i++){
    visited[i]=false;}
    visited[0]=true;
    vector<int>::iterator i;
    q.push_back(0);
    while(!q.empty()){
        s=q.front();
        res.push_back(s);
        q.pop_front();
        for(i = g[s].begin(); i != g[s].end(); i++){
            if(visited[*i]==false){
                visited[*i]=true;
                q.push_back(*i);
            }
        }
    }
    return res;
}