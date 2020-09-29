#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclicUtil(vector<int> g[],int v,int vis[],int parent){
    vis[v]=true;
    for(int i=0;i<g[v].size();i++){
        if(!vis[g[v][i]]){
            if(isCyclicUtil(g,g[v][i],vis,v))return true;
        }else if(g[v][i]!=parent){
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> g[], int v)
{
   // Your code here
   int vis[v];
   for(int i=0;i<v;i++)
   vis[i]=false;
   for(int i=0;i<v;i++){
       if(vis[i]==false){
           if(isCyclicUtil(g,i,vis,-1))
           return true;
       }
   }
   return false;
   
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends