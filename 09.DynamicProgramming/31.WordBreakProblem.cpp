//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {
    //code here
    int n=A.size();
    unordered_set<string> s;
    for(int i=0;i<B.size();i++)
    s.insert(B[i]);
    vector<int> dp(n+1,0);
    vector<int> matched_index;
    matched_index.push_back(-1);
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=matched_index.size()-1;j>=0;j--){
            string str =  A.substr(matched_index[j]+1,i-matched_index[j]);
            if(s.find(str)!=s.end()){
                flag=true;
                break;
            }
        }
        if(flag){
            dp[i]=true;
            matched_index.push_back(i);
        }
    }
    return dp[n-1];
}