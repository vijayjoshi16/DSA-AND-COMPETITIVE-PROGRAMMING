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
	    string s;
	    cin>>s;
	    int n=s.length();
	    int dp[n][n]={};
	    for(int i=0;i<n;i++)
	    dp[i][i]=1;
	    int maxi=1;
	    string ans = "";
	    ans+=s[0];
	    for(int i=0;i<n-1;i++){
	        if(s[i]==s[i+1]){
	            dp[i][i+1]=1;
	            if(maxi==1){
	                ans="";
	                ans+=s[i];
	                ans+=s[i+1];
	            }
	            maxi=2;
	        }
	    }
	    for(int k=3;k<=n;k++){
	        for(int i=0;i<n-k+1;i++){
	            if(dp[i+1][i+k-2]==1&&s[i]==s[i+k-1]){
	                dp[i][i+k-1]=1;
	                if(k>maxi){
	                    maxi=k;
	                    ans=s.substr(i,k);
	                }
	            }
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}