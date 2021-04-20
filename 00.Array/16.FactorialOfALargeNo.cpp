#define lli long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define MAX 10000
using namespace std;

int main()
 {
	fast;
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    lli res[MAX];
	    res[0]=1;
	    lli res_size=1,carry,tmp,ctr;
	    for(lli i=2;i<=n;i++){
	        carry=0;
	        for(lli j=0;j<res_size;j++){
	            tmp=res[j]*i+carry;
	            res[j]=tmp%10;
	            carry=tmp/10;
	        }
	        while(carry){
	            res[res_size]=carry%10;
	            carry/=10;
	            res_size++;
	        }
	    }
	    for(lli i=res_size-1;i>=0;i--)
	    cout<<res[i];
	    cout<<"\n";
	    
	}
	return 0;
}