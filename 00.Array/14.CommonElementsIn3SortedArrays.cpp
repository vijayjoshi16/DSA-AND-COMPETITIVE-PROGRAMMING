#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            int pre1=INT_MIN,pre2=INT_MIN,pre3=INT_MIN;
            vector<int> com;
            int i1=0,i2=0,i3=0;
            while(i1<n1 && i2<n2 && i3<n3){
                while(a[i1]==pre1&&i1<n1){
                    i1++;
                }
                while(b[i2]==pre2&&i2<n2){
                    i2++;
                }
                while(c[i3]==pre3&&i3<n3){
                    i3++;
                }
                if(a[i1]==b[i2]&&a[i1]==c[i3]){
                    com.push_back(a[i1]);
                    pre1=a[i1];
                    pre2=b[i2];
                    pre3=c[i3];
                    i1++;
                    i2++;
                    i3++;
                }else if(a[i1]<=b[i2]&&b[i2]<=c[i3]){
                    pre1=a[i1];
                    i1++;
                }else if(a[i1]<=c[i3]&&c[i3]<=b[i2]){
                    pre1=a[i1];
                    i1++;
                }else if(b[i2]<=a[i1]&&a[i1]<=c[i3]){
                    pre2=b[i2];
                    i2++;
                }else if(b[i2]<=c[i3]&&c[i3]<=a[i1]){
                    pre2=b[i2];
                    i2++;
                }else{
                    pre3=c[i3];
                    i3++;
                }
            }
            return com;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends