

 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclicUtil(vector<int> adj[],bool *vis,bool *s,int i){
   if(!vis[i]){
       vis[i]=true;
       s[i]=true;
       for(int j=0;j<adj[i].size();j++){
           if(!vis[adj[i][j]]&&isCyclicUtil(adj,vis,s,adj[i][j]))
           return true;
           else if(s[adj[i][j]])
           return true;
       }
   }
   s[i]=false;
   return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool *vis=new bool[V];
    bool *s=new bool[V];
    for(int i=0;i<V;i++){
        vis[i]=false;
        s[i]=false;
    }
    for(int i=0;i<V;i++){
        if(isCyclicUtil(adj,vis,s,i))
        return true;
    }
    return false;
    
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends