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
	    int l,n;
	    cin>>l>>n;
	    lli a[l];
	    for(int i=0;i<l;i++)
	    cin>>a[i];
	    unordered_set<int> m;
	    bool found=false;
	    for(int i=0;i<l;i++){
	        if(m.find(a[i]+n)!=m.end()||m.find(a[i]-n)!=m.end()){
	            //cout<<a[i]<<"b\n";
	            found=true;
	            break;
	        }else{
	            //cout<<a[i]<<"a\n";
	            m.insert(a[i]);
	        }
	    }
	    if(found)
	    cout<<"1\n";
	    else
	    cout<<"-1\n";
	}
	return 0;
}