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
	string s;
	cin>>s;
	lln n=s.length();
	lln cm=1,ct=1;
	for(lln i=1;i<n;i++){
		if(s[i]==s[i-1]){
			ct++;
		}else{
			if(ct>cm)
				cm=ct;
			ct=1;
		}
	}
	if(ct>cm)
		cm=ct;
	cout<<cm;
 
	return 0;
}