#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(S>9*D)
        return "-1";
        string s="";
        int d=D;
        while(D){
            if(S<=9*(D-1)){
                if(d==D){
                    S-=1;
                    s=s+"1"; 
                }else{
                    s=s+"0";
                }
                
            }else{
                s=s+to_string(S-9*(D-1));
                S=9*(D-1);
            }
            D--;
        }
        return s;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends