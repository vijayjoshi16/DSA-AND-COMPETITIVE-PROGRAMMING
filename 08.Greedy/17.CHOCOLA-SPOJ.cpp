#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    int x[m-1],y[n-1];
	    for(int i=0;i<m-1;i++)
	    cin>>x[i];
	    for(int i=0;i<n-1;i++)
	    cin>>y[i];
	    long long int ctr=0;
	    sort(x,x+m-1);
	    sort(y,y+n-1);
	    int i1=m-2,i2=n-2;
	    int vp=1,hp=1;
	    while(i1>=0&&i2>=0){
	        if(x[i1]>=y[i2]){
	            ctr+=x[i1]*vp;
	            hp++;
	            i1--;
	        }else{
	            ctr+=y[i2]*hp;
	            vp++;
	            i2--;
	        }
	    }
	    while(i1>=0){
	        ctr+=x[i1]*vp;
	        i1--;
	    }
	    while(i2>=0){
	        ctr+=y[i2]*hp;
	        i2--;
	    }
	    cout<<ctr<<"\n";
	}
	
	return 0;
} 