#include <bits/stdc++.h>
#define lli int
using namespace std;
 
int main() {
	// your code goes here
	lli t;
	cin>>t;
	while(t--){
	    lli w,h,n;
	    cin>>w>>h>>n;
	    vector<lli> x(n),y(n);
	    for(lli i=0;i<n;i++)
	    cin>>x[i]>>y[i];
	    if(n==0){
	        cout<<w*h<<"\n";
	        continue;
	    }
	    sort(x.begin(),x.end());
	    sort(y.begin(),y.end());
	    lli maxx=0,maxy=0;
	    maxx=(x[0]-1)>maxx?(x[0]-1):maxx;
	    maxy=(y[0]-1)>maxy?(y[0]-1):maxy;
	    for(int i=1;i<n;i++)
	    maxx=(x[i]-x[i-1]-1>maxx)?x[i]-x[i-1]-1:maxx;
	    maxx=(w-x[n-1])>maxx?w-x[n-1]:maxx;
	    for(int i=1;i<n;i++)
	    maxy=(y[i]-y[i-1]-1>maxy)?y[i]-y[i-1]-1:maxy;
	    maxy=(h-y[n-1])>maxy?h-y[n-1]:maxy;
	    cout<<(maxx)*(maxy)<<"\n";
	}
	return 0;
}
 