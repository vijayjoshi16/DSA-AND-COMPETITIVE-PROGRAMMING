#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            if(m.find(arr[i])==m.end()){
                m[arr[i]]=1;
            }else{
                m[arr[i]]++;
            }
        }
        int fm=INT_MIN,sm=INT_MIN;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>fm){
                sm=fm;
                fm=it->second;
            }else if(it->second>sm&&it->second!=fm){
                sm=it->second;
            }
        }
        for(int i=0;i<n;i++)
        if(m[arr[i]]==sm)
        return arr[i];
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends