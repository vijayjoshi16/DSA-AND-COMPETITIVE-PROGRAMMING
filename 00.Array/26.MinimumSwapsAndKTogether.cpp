// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *a, int n, int k) {
    // Complet the function
    int ctr=0;
    for(int i=0;i<n;i++){
        if(a[i]<=k)
        ctr++;
    }
    int mini=0;
    for(int i=0;i<ctr;i++){
        if(a[i]>k)
        mini++;
    }
    int cnt=mini;
    for(int i=ctr;i<n;i++){
        if(a[i-ctr]>k)
        cnt--;
        if(a[i]>k)
        cnt++;
        mini=min(mini,cnt);
    }
    return mini;
}
