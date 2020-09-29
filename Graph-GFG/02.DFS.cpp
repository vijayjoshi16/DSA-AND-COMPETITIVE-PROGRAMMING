#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
vector<int> r;
void DFSUtil(int v,vector<int> g[],bool vis[]){
    vis[v]=true;
    r.push_back(v);
    vector<int>::iterator i;
    for(i=g[v].begin();i!=g[v].end();i++){
        if(!vis[*i]){
          DFSUtil(*i,g,vis);
        }
    }
}


vector <int> dfs(vector<int> g[], int N)
{
    r.clear();
    bool vis[N];
    for(int i=0;i<N;i++)
    vis[i]=false;
    DFSUtil(0,g,vis);
    return r;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends