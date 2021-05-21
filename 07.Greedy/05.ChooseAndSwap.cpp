#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        int i,j;
        int n=a.length();
        int check[26];
        memset(check,-1,sizeof(check));
        for(i=0;i<n;i++){
            if(check[a[i]-'a']==-1)
            check[a[i]-'a']=i;
        }
        bool flag=false;
        for(i=0;i<n;i++){
            for(j=0;j<a[i]-'a';j++){
                if(check[j]>check[a[i]-'a']){
                    flag=true;
                    break;
                }
            }
            if(flag==true)
            break;
        }
        if(flag){
            char c1=a[i];
            char c2=char(j+'a');
            for(i=0;i<n;i++){
                if(a[i]==c1)
                a[i]=c2;
                else if(a[i]==c2)
                a[i]=c1;
            }
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends