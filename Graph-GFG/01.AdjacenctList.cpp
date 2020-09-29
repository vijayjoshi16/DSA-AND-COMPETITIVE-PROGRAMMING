#define lli long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
using namespace std;

int main()
 {
	fast;
	int t,v,a,b;lli e,tmp;
	cin>>t;
	while(t--){
	    cin>>v>>e;
	    vector<int> adj[v];
	    tmp=e;
	    while(tmp--){
	        cin>>a>>b;
	        adj[a].pb(b);
	        adj[b].pb(a);
	    }
	    for(int i=0;i<v;i++){
	        cout<<i;
	        for(int j=0;j<adj[i].size();j++){
	            cout<<"-> "<<adj[i][j];
	        }
	        cout<<"\n";
	    }
	}
	return 0;
}