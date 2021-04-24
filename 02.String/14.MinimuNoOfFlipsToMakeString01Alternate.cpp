#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int f1=0,f2=0,n=s.length();
    for(int i=0;i<n;i++){
        if(i%2==0&&s[i]=='1')
        f1++;
        else if(i%2==1&&s[i]=='0')
        f1++;
    }
    for(int i=0;i<n;i++){
        if(i%2==0&&s[i]=='0')
        f2++;
        else if(i%2==1&&s[i]=='1')
        f2++;
    }
    return min(f1,f2);
}