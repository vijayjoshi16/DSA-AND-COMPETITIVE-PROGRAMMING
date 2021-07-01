// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string str) {
        // code here
        int n = str.length();
        stack<int> s;
        s.push(-1);
        int maxi=0;
        for(int i=0;i<n;i++){
            if(str[i]=='(')
            s.push(i);
            else{
                if(!s.empty())
                s.pop();
                if(!s.empty()){
                    maxi=i-s.top()>maxi?i-s.top():maxi;
                }else{
                    s.push(i);
                }
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends