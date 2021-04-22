#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends


/*You are required to complete this method*/
class Solution{
  public:
  
    int getMaxArea(int hist[], int n) 
    { 
        // Create an empty stack. The stack holds indexes  
        // of hist[] array. The bars stored in stack are  
        // always in increasing order of their heights. 
        stack<int> s; 
      
        int max_area = 0; // Initialize max area 
        int tp;  // To store top of stack 
        int area_with_top; // To store area with top bar 
                           // as the smallest bar 
      
        // Run through all bars of given histogram 
        int i = 0; 
        while (i < n) 
        { 
            // If this bar is higher than the bar on top  
            // stack, push it to stack 
            if (s.empty() || hist[s.top()] <= hist[i]) 
                s.push(i++); 
      
            // If this bar is lower than top of stack,  
            // then calculate area of rectangle with stack  
            // top as the smallest (or minimum height) bar.  
            // 'i' is 'right index' for the top and element  
            // before top in stack is 'left index' 
            else
            { 
                tp = s.top();  // store the top index 
                s.pop();  // pop the top 
      
                // Calculate the area with hist[tp] stack  
                // as smallest bar 
                area_with_top = hist[tp] * (s.empty() ? i :  
                                       i - s.top() - 1); 
      
                // update max area, if needed 
                if (max_area < area_with_top) 
                    max_area = area_with_top; 
            } 
        } 
      
        // Now pop the remaining bars from stack and calculate 
        // area with every popped bar as the smallest bar 
        while (s.empty() == false) 
        { 
            tp = s.top(); 
            s.pop(); 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                    i - s.top() - 1); 
      
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
      
        return max_area; 
    } 
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int hist[m]={};
        for(int i=0;i<m;i++)
        hist[i]=M[0][i];
        int maxa = getMaxArea(hist,m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j])
                hist[j]+=1;
                else
                hist[j]=0;
            }
            maxa = max(maxa,getMaxArea(hist,m));
        }
        return maxa;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends