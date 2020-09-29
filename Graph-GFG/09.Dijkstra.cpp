#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

int minDistance(vector<int> dist,vector<bool> sptSet,int V){
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++){
        if(sptSet[i]==false&&dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    vector<int> dist(V,INT_MAX);
    vector<bool> sptSet(V,false);
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int min=minDistance(dist,sptSet,V);
        sptSet[min]=true;
        for(int v=0;v<V;v++){
            if(!sptSet[v]&&g[min][v]&&dist[min]+g[min][v]<dist[v]){
                dist[v]=dist[min]+g[min][v];
            }
        }
    }
    return dist;
    
}