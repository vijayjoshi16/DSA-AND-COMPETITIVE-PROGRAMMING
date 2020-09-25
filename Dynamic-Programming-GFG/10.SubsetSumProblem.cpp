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
	    int a[n];
	    int i,j,k,l;
	    lli sum=0;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    if(sum%2!=0){
	        cout<<"NO\n";
	        continue;
	    }
	    bool isSubset[n+1][sum/2+1];
	    for(i=0;i<=n;i++){
	        isSubset[i][0]=true;
	    }
	    for(i=1;i<=sum/2;i++){
	        isSubset[0][i]=false;
	    }
	    for(i=1;i<=n;i++){
	        for(j=1;j<=sum/2;j++){
	            if(a[i-1]<=j){
	                isSubset[i][j]=isSubset[i-1][j-a[i-1]]||isSubset[i-1][j];
	            }else{
	                isSubset[i][j]=isSubset[i-1][j];
	            }
	        }
	    }
	    if(isSubset[n][sum/2])
	    cout<<"YES\n";
	    else
	    cout<<"NO\n";
	    
	}
	return 0;
}