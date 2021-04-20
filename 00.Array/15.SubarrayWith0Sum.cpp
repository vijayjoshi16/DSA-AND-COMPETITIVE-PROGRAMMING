// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends


//Complete this function
bool subArrayExists(int a[], int n)
{
    //Your code here
    unordered_set<long long int> s;
    s.insert(0);
    long long int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]==0||s.find(a[i]+sum)!=s.end())
        return true;
        sum+=a[i];
        s.insert(sum);
    }
    return false;
}


