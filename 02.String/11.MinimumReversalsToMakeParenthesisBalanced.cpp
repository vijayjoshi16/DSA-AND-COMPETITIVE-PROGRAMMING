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
	    if(n%2){
	        cout<<"-1\n";
	        continue;
	    }
	    int ctr=0,co=0;
	    for(int i=0;i<n;i++){
	        if(s[i]=='{')
	        co++;
	        else{
	            if(i-co+1>co){
	                s[i]='{';
	                co++;
	                ctr++;
	            }
	        }
	    }
        int i=n-1;
        while(i>=0&&co!=n/2){
            if(s[i]=='{'){
                s[i]='}';
                ctr++;
                co--;
            }
            i--;
        }
        cout<<ctr<<"\n";
	}
	return 0;
}