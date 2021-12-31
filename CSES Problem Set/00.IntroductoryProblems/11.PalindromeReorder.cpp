#include<bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
using namespace std;
 
int main()
 {
	fast;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s;
	cin>>s;
	unordered_map<char,lli> m;
	for(lli i=0;i<s.length();i++)
	m[s[i]]++;
	lli oc=0;
	char odc;
	for(auto i:m){
	    if(i.second%2==1){
	        oc++;
	        odc=i.first;
	        if(oc>1)
	        break;
	    }
	}
	if(oc<=1){
	    string res="";
	    if(oc==0){
	        for(auto i:m){
	            string tmp(i.second/2,i.first);
	            res=tmp+res+tmp;
	        }
	    }else{
	        res=res+odc;
	        m[odc]--;
	        for(auto i:m){
	            string tmp(i.second/2,i.first);
	            res=tmp+res+tmp;
	        }
	    }
	    cout<<res;
	}else{
	    cout<<"NO SOLUTION";
	}
	
	return 0;
}