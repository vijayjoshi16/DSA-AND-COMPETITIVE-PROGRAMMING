#include <boost/multiprecision/cpp_int.hpp> 
#define lli long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007

using boost::multiprecision::cpp_int;
using namespace std;

int main()
 {
	fast;
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    if(n<=1)
	    cout<<n<<"\n";
	    else{
	        cpp_int catalan[n+1];
	        catalan[0]=catalan[1]=1;
	        for(int i=1;i<=n;i++){
	            catalan[i]=0;
	            for(int j=0;j<i;j++){
	                catalan[i]+=catalan[j]*catalan[i-j-1];
	            }
	        }
	        cout<<catalan[n]<<"\n";
	    }
	}
	return 0;
}