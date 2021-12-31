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
	lln x[n];
	for(lln i=0;i<n;i++)
		cin>>x[i];
	lln ctr=0;
	for(lln i=1;i<n;i++){
		if(x[i]<x[i-1]){
			ctr+=x[i-1]-x[i];
			x[i]=x[i-1];
		}
	}
	cout<<ctr;
 
	return 0;
}