// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &str) {
    // code here
    int n=str.length();
    unordered_map<char,int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    int sum=m[str[n-1]];
    int ten=1;
    for(int i=n-2;i>=0;i--){
        if(m[str[i]]<m[str[i+1]]){
            sum-=m[str[i]];
        }else if(m[str[i]]>m[str[i+1]]){
            sum+=m[str[i]];
            ten++;
        }else{
            sum+=m[str[i]];
        }
    }
    return sum;
}