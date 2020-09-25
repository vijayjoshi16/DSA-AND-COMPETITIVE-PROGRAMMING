#define lli long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;

int main()
 {
	int t,p,q;
	cin>>t;
	while(t--){
	    cin>>p>>q;
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    int ed[p+1][q+1];
	    for(int i=0;i<=p;i++){
	        for(int j=0;j<=q;j++){
	            if(!i)
	            ed[i][j]=j;
	            else if(!j)
	            ed[i][j]=i;
	            else if(s1.at(i-1)==s2.at(j-1))
	            ed[i][j]=ed[i-1][j-1];
	            else
	            ed[i][j]=min(ed[i][j-1],min(ed[i-1][j-1],ed[i-1][j]))+1;
	        }
	    }
	    cout<<ed[p][q]<<"\n";
	}
	
	return 0;
}