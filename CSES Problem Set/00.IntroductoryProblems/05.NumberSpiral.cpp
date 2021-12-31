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
	lln t,x,y;
	cin>>t;
	while(t--){
		cin>>y>>x;
		lln tmp=max(x,y);
		lln ctr=(tmp-1)*(tmp-1);
		if(tmp%2==0){
			if(x>=y){
				ctr+=y;
			}else{
				ctr+=y+(y-x);
			}
		}else{
			if(y>=x){
				ctr+=x;
			}else{
				ctr+=x+(x-y);
			}
		}
		cout<<ctr<<"\n";
	}
 
	return 0;
}