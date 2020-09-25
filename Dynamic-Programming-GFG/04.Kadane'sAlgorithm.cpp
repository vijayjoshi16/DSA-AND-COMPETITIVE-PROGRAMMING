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
	lli t,n,ip,curr,maxi;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<lli> a;
	    for(int i=0;i<n;i++){
	        cin>>ip;
	        a.pb(ip);
	    }
	    curr=0,maxi=INT_MIN;
	    for(int i=0;i<n;i++){
	        curr=max(a[i],a[i]+curr);
	        maxi=max(maxi,curr);
	    }
	    cout<<maxi<<"\n";
	}
	return 0;
}