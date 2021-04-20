#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}// } Driver Code Ends


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int a[], int N)
{
  //Your code here
  int n=*max_element(a,a+N);
  int tmp[n]={};
  for(int i=0;i<N;i++)
  tmp[a[i]-1]=1;
  int maxi=1;
  for(int i=0;i<n;i++){
      if(tmp[i]==1){
          int ctr=1;
          while(i<n-1 && tmp[i+1]==1){
          i++;
              ctr++;
          }
          maxi=max(maxi,ctr);
      }
  }
  return maxi;
}