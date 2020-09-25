#define lli long long int
#define ull unsigned long long

using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=1)
        cout<<n<<"\n";
        else{
            lli dp[n+1];
            dp[0]=0;
            dp[1]=1;
            cout<<dp[1]<<" ";
            for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
            cout<<dp[i]<<" ";
            }
            cout<<"\n";
        }
    }
}