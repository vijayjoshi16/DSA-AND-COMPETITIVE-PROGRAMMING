#include <bits/stdc++.h>
#define lli long long int
using namespace std;
 
int main() {
	// your code goes here
	lli t,n;
	while(1){
	    cin>>n;
	    if(n==0)break;
	    lli a[n];
	    for(lli i=0;i<n;i++)cin>>a[i];
	    
	    lli seller=0,buyer=0,res=0,trans;
	    
	    while(1){
	        while(seller<n&&a[seller]>=0)seller++;
	        while(buyer<n&&a[buyer]<=0)buyer++;
	        if(seller==n||buyer==n)break;
	        trans=min(a[buyer],-a[seller]);
	        res+=trans*abs(buyer-seller);
	        a[buyer]-=trans;
	        a[seller]+=trans;
	    }
	    cout<<res<<"\n";
	}
	return 0;
}
 