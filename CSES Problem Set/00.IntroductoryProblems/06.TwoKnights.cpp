#include<bits/stdc++.h>
#define lln long long int
#define ull unsigned long long
using namespace std;
 
int main()
 {
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	lln n;
	cin>>n;
	for(lln i=1;i<=n;i++){
		cout<<i*i*(i*i-1)/2-4*(i-1)*(i-2)<<"\n";
	}
 
	return 0;
}