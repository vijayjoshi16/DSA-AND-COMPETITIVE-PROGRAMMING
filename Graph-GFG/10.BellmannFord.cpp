#include<bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
using namespace std;

struct edge{
	int src,dest,wt;
};

void BellmanFord(vector<edge> edges,int v,int source,int e){
	int dist[v];
	for(int i=0;i<v;i++)
		dist[i]=INT_MAX;
	dist[source]=0;

	for(int i=1;i<v;i++){
		for(int j=0;j<e;j++){
			int s=edges[j].src;
			int d=edges[j].dest;
			int w=edges[j].wt;
			if(dist[s]!=INT_MAX && dist[d]>dist[s]+w){
				dist[d]=dist[s]+w;
			}
		}
	}
	//CHECK FOR NEGATIVE WEIGHT CYCLES
	for(int i=0;i<e;i++){
		int s=edges[i].src;
		int d=edges[i].dest;
		int w=edges[i].wt;
		if(dist[s]!=INT_MAX&&dist[s]+w<dist[d]){
			cout<<"Negative wt cycle detected!!!";
			return;
		}
	}
	cout<<"Vertex\tDist from src\n";
	for(int i=0;i<v;i++){
		cout<<i<<"   \t"<<dist[i]<<"\n";
	}

}

int main()
 {
	int v;
	cin>>v;
	int e;
	cin>>e;
	//vector representing all the edges
	vector<edge> edges(e);
	//Input e edges
	for(int i=0;i<e;i++){
		cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
	}
	int source;
	cin>>source;
	BellmanFord(edges,v,source,e);
	
	return 0;
}