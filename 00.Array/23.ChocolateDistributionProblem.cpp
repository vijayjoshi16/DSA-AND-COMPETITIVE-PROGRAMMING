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
	    lli n;
	    cin>>n;
	    lli a[n];
	    for(lli i=0;i<n;i++)
	    cin>>a[i];
	    lli m;
	    cin>>m;
	    sort(a,a+n);
	    int mini=INT_MAX;
	    for(lli i=0;i+m-1<n;i++){
	        mini=(a[i+m-1]-a[i])<mini?(a[i+m-1]-a[i]):mini;
	    }
	    cout<<mini<<"\n";
	}
	return 0;
}