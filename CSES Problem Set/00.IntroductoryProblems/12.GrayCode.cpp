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
	int n;
	cin>>n;
	vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    for(lli i=2;i<(1<<n);i=i<<1){
        for(lli j=i-1;j>=0;j--)
        ans.push_back(ans[j]);
        for(lli j=0;j<i;j++)
        ans[j]="0"+ans[j];
        for(lli j=i;j<2*i;j++)
        ans[j]="1"+ans[j];
    }
    for(lli i=0;i<ans.size();i++)
    cout<<ans[i]<<"\n";
    
	return 0;
}