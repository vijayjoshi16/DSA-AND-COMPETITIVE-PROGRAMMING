#include<bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
using namespace std;
 
vector<pair<int,int>> ans;
 
void towerOfHanoi(lli n,int src,int dest,int aux){
    if(n==1){
        ans.push_back({src,dest});
        return;
    }
    towerOfHanoi(n-1,src,aux,dest);
    ans.push_back({src,dest});
    towerOfHanoi(n-1,aux,dest,src);
}
 
 
int main()
 {
	fast;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	lli n;
	cin>>n;
	
	towerOfHanoi(n,1,3,2);
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++){
	    cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	return 0;
}