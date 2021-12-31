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
	if(n==2||n==3){
		cout<<"NO SOLUTION";
	}else if(n==4){
		cout<<"2 4 1 3";
	}else{
		for(lln i=1;i<=n;i+=2){
			cout<<i<<" ";
		}
		for(lln i=2;i<=n;i+=2)
		{
			cout<<i<<" ";
		}
	}
 
	return 0;
}