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
	    int n;
	    cin>>n;
	    int a[n];
	    int i,j,k;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    int lis[n];
	    lis[0]=1;
	    for(i=1;i<n;i++){
	        lis[i]=1;
	        for(j=0;j<i;j++){
	            if(a[j]<a[i]){
	                lis[i]=max(lis[i],1+lis[j]);
	            }
	        }
	    }
	    cout<<*max_element(lis,lis+n)<<"\n";
	}
	return 0;
}