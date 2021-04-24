#include <bits/stdc++.h>
using namespace std;

const int no_of_chars = 256;

string findSubString(string str);

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;

        cout << findSubString(str).size() << endl;
    }
    return 0;
}
// } Driver Code Ends




string findSubString(string s)
{
    // Your code goes here
    int n=s.length();
    bool vis[256]={false};
    int count=0;
    for(int i=0;i<n;i++){
        if(vis[s[i]]==false){
            vis[s[i]]=true;
            count++;
        }
    }
    //cout<<count<<"\n";
    int start=0,ctr=0,mini=n,mins=0;
    int curr[256]={};
    for(int i=0;i<n;i++){
        curr[s[i]]++;
        if(curr[s[i]]==1)
        ctr++;
        //cout<<ctr<<"\n";
        if(ctr==count){
            while(curr[s[start]]>1){
                curr[s[start]]--;
                start++;
            }
            //cout<<start<<"\n";
            if(i-start+1<mini){
                mini=i-start+1;
                mins=start;
            }
        }
    }
    return s.substr(mins,mini);
}