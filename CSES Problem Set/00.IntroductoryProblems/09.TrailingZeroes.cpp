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
	lli cnt=0;
	for(lli i=5;n/i>=1;i*=5)
		cnt+=n/i;
	cout<<cnt;
	
	return 0;
}