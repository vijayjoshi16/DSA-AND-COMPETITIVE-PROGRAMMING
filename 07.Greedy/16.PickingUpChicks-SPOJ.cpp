#include <bits/stdc++.h>
using namespace std;
#define lli long long int
 
int main() {
	// your code goes here
	int c;
	cin>>c;
	int c1=1;
	while(c--){
	    lli n,k,b,t;
	    cin>>n>>k>>b>>t;
	    lli x[n],v[n];
	    for(lli i=0;i<n;i++)cin>>x[i];
	    for(lli i=0;i<n;i++)cin>>v[i];
	    vector<pair<lli,double>> tmp;
	    for(int i=0;i<n;i++)tmp.push_back({x[i],double(double(b-x[i])/double(v[i]))});
	    
	    sort(tmp.begin(),tmp.end());
	    
	    lli swap=0;
	    lli s=0;
	    lli ctr=0;
	    for(lli i=n-1;i>=0;i--){
	        if(tmp[i].second>t){
	            swap++;
	        }else{
	            s+=swap;
	            ctr++;
	        }
	        if(ctr==k)
	        break;
	    }
	    if(ctr==k)cout<<"Case #"<<c1++<<": "<<s<<"\n";
	    else cout<<"Case #"<<c1++<<": IMPOSSIBLE"<<"\n";
	}
	return 0;
}