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
	cout<<n;
	while(n!=1){
		if(n%2==0){
			n/=2;
			cout<<" "<<n;
		}else{
			n=n*3+1;
			cout<<" "<<n;
		}
	}
 
	return 0;
}