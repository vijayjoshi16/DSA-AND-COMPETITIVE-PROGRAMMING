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
	    int n,k;
	    cin>>n>>k;
	    int i,j;
	    lli dp[n+1][k+1];
	    for(i=0;i<=n;i++){
	        dp[i][0]=1;
	    }
	    for(i=1;i<=k;i++){
	        dp[0][i]=0;
	    }
	    for(i=1;i<=n;i++){
	        for(j=1;j<=k;j++){
	            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
	        }
	    }
	    cout<<dp[n][k]%MOD<<"\n";
	}
	return 0;
}