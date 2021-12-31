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
	lln n,j;
	cin>>n;
	lln sum=n*(n+1)/2;
	for(lln i=0;i<n-1;i++){
		cin>>j;
		sum-=j;
	}
	cout<<sum;
 
	return 0;
}