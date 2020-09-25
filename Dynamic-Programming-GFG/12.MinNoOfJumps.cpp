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
	    lli i,j,k,sum=1;
	    int tmp;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    if(n==1){
	        cout<<"0\n";
	        continue;
	    }
	    lli dp[n];
	    dp[0]=0;
	    for(i=n-1;i>0;i--){
	        tmp=0;
	        for(j=0;j<i;j++){
	            if(j+a[j]>=i){
	                tmp=1;
	                dp[i]=j;
	                break;
	            }
	        }
	        if(tmp==0){
	            break;
	        }
	    }
	    if(tmp==0){
	        cout<<"-1\n";
	    }else{
	        tmp=dp[n-1];
	        while(tmp){
	            sum++;
	            tmp=dp[tmp];
	        }
	        cout<<sum<<"\n";
	    }
	}
	return 0;
}