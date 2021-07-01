#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t,h,a;
	cin>>t;
	while(t--){
	    cin>>h>>a;
	    char s='a';
	    h+=3;
	    a+=2;
	    int tm=1;
	    while(1){
	        if(s=='a'){
	            if(h>5&&a>10){
	                h-=5;
	                a-=10;
	                tm++;
	                s='w';
	            }else if(h>20){
	                h-=20;
	                a+=5;
	                s='f';
	                tm++;
	            }else{
	                break;
	            }
	        }else{
	            s='a';
        	    h+=3;
        	    a+=2;
        	    tm++;
	        }
	    }
	    cout<<tm<<"\n";
	}
	return 0;
}