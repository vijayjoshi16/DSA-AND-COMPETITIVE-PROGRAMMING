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

int wordBreak(string s, vector<string> &B) {
    //code here
    int ind=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(find(B.begin(),B.end(),s.substr(ind,i-ind+1))!=B.end()){
            ind=i+1;
        }
    }
    return ind==n;
}