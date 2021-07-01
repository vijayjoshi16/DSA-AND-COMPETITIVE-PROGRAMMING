//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        unordered_map<int,stack<int>> s;
        unordered_map<int,queue<int>> q;
        for(int i=0;i<2*e;i+=2){
            s[A[i]].push(A[i+1]);
        }
        for(int i=0;i<2*e;i+=2){
            q[B[i]].push(B[i+1]);
        }
        for(auto i:s){
            stack<int> st=i.second;
            queue<int> qt=q[i.first];
            while(!st.empty()&&!qt.empty()){
                if(st.top()!=qt.front()){
                    return 0;
                }
                st.pop();
                qt.pop();
            }
            if(!st.empty()||!qt.empty())
            return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends