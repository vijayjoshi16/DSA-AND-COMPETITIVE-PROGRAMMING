//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int freq[26]={0};
        int ans=0;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        priority_queue<int> q;
        for(int i=0;i<26;i++){
            q.push(freq[i]);
        }
        while(k--){
            int top=q.top();
            q.pop();
            top--;
            q.push(top);
        }
        while(!q.empty()){
            int tmp=q.top();
            ans+=tmp*tmp;
            q.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends