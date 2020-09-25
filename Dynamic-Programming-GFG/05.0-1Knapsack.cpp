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
	int t,n,w;
	cin>>t;
	while(t--){
	    cin>>n>>w;
	    int val[n],wt[n];
	    int i,j;
	    for(i=0;i<n;i++)
	    cin>>val[i];
	    for(i=0;i<n;i++)
	    cin>>wt[i];
	    lli dp[n+1][w+1];
	    for(i=0;i<n+1;i++){
	        for(j=0;j<w+1;j++){
	            if(i==0||j==0)
	            dp[i][j]=0;
	            else if(j>=wt[i-1]){
	                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    cout<<dp[n][w]<<"\n";
	}
	return 0;
}