#include <bits/stdc++.h>
using namespace std;
#define lli long long int
 
int main() {
	// your code goes here
	lli t;
	cin>>t;
	while(t--){
	    lli n;
	    cin>>n;
	    lli p[n];
	    lli c1=0,c=0,j=0;
	    for(lli i=0;i<n;i++){
	        cin>>p[i];
	        if(p[i]==1)c1++;
	        else{c++;p[j++]=p[i];}
	    }
	    sort(p,p+c);
	    for(lli i=0;i<c1;i++)cout<<"1 ";
	    if(c==2&&p[0]==2&&p[1]==3)cout<<"2 3";
	    else{
	        for(lli i=c-1;i>=0;i--)cout<<p[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
 