#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

int minKey(int key[],bool mstSet[],int V){
    int min=INT_MAX,minindex;
    for(int i=0;i<V;i++){
        if(!mstSet[i]&&key[i]<min){
            min=key[i];
            minindex=i;
        }
    }
    return minindex;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    int parent[V];
    int key[V];
    bool mstSet[V];
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    int ctr=V-1;
    while(ctr--){
        int mk=minKey(key,mstSet,V);
        mstSet[mk]=true;
        for(int j=0;j<V;j++){
            if(graph[mk][j]&&mstSet[j]==false&&graph[mk][j]<key[j]){
                parent[j]=mk;
                key[j]=graph[mk][j];
            }
        }
    }
    long long int sum=0;
    for(int i=0;i<V;i++)
    sum+=graph[i][parent[i]];
    return sum;
}