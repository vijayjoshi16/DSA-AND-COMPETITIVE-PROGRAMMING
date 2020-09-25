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
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int ctr=0;
	    while(n){
	        if(!(n%2))
	        n/=2;
	        else
	        n-=1;
	        ctr++;
	        //cout<<"Ctr="<<ctr<<"and n="<<n<<"\n";
	    }
	    cout<<ctr<<"\n";
	}
	return 0;
}