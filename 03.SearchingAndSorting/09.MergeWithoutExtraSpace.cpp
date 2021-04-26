#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


int getGap(int gap){
    if(gap<=1)
    return 0;
    return gap/2+gap%2;
}

//User function template for C++
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int gap = n+m,i,j;
	    for(gap = getGap(gap);gap>0;gap=getGap(gap)){
	        for(i=0;i<n-gap;i++){
	            if(arr1[i]>arr1[i+gap]){
	                int tmp=arr1[i];
	                arr1[i]=arr1[i+gap];
	                arr1[i+gap]=tmp;
	            }
	        }
	        for(j=gap>n?gap-n:0;i<n&&j<m;i++,j++){
	            if(arr1[i]>arr2[j]){
	                int tmp=arr1[i];
	                arr1[i]=arr2[j];
	                arr2[j]=tmp;
	            }
	        }
	        if(j<m){
	            for(j=0;j<m-gap;j++){
	            if(arr2[j]>arr2[j+gap]){
	                int tmp=arr2[j];
	                arr2[j]=arr2[j+gap];
	                arr2[j+gap]=tmp;
	            }
	            }
	        }
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends