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
	int t;
	cin>>t;
	while(t--){
	    lli m,n;
	    cin>>m>>n;
	    lli a[m],b[n];
	    unordered_set<lli> as;
	    for(lli i=0;i<m;i++){
	        cin>>a[i];
	        as.insert(a[i]);
	    }
	    int flag=0;
	    for(lli i=0;i<n;i++){
	        cin>>b[i];
	        if(flag==0){
	            if(as.find(b[i])==as.end())
	            flag=1;
	        }
	    }
	    if(!flag)
	        cout<<"Yes\n";
	    else
	        cout<<"No\n";
	    
	}
	return 0;
}