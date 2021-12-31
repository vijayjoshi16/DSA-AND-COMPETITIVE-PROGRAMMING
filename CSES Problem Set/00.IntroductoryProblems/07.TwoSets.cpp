#include<bits/stdc++.h>
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
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	lli n;
	cin>>n;
	if(n%4==1||n%4==2)
		cout<<"NO";
	else{
		cout<<"YES\n";
		if(n%4==0){
			cout<<n/2<<"\n";
			for(lli i=1;i<=n;i+=4){
				cout<<i<<" "<<i+3<<" ";
			}
			cout<<"\n"<<n/2<<"\n";
			for(lli i=2;i<=n;i+=4){
				cout<<i<<" "<<i+1<<" ";
			}
		}else{
			cout<<(n-3)/2+2<<"\n";
			cout<<"1 2 ";
			for(lli i=4;i<=n;i+=4){
				cout<<i<<" "<<i+3<<" ";
			}
			cout<<"\n"<<(n-3)/2+1;
			cout<<"\n3 ";
			for(lli i=5;i<=n;i+=4){
				cout<<i<<" "<<i+1<<" ";
			}
		}
	}
	
	return 0;
}