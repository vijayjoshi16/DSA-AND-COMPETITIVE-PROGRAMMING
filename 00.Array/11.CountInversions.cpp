#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long int merge(long long a[],long long tmp[],long long n,long long left,long long mid,long long right){
    long long inversions=0;
    long long i=left,j=mid+1,k=left;
    while(i<=mid && j<=right){
        if(a[i]<=a[j]){
            tmp[k++]=a[i++];
        }else{
            inversions+=(mid-i+1);
            tmp[k++]=a[j++];
        }
    }
    while(i<=mid){
        tmp[k++]=a[i++];
    }
    while(j<=right){
        tmp[k++]=a[j++];
    }
    for(long long ind=left;ind<=right;ind++)
    a[ind]=tmp[ind];
    return inversions;
}

long long int mergeSort(long long a[], long long tmp[], long long n,long long left,long long right){
    long long inversions=0;
    if(left<right){
        long long mid = (left+right)/2;
        inversions+=mergeSort(a,tmp,n,left,mid);
        inversions+=mergeSort(a,tmp,n,mid+1,right);
        inversions+=merge(a,tmp,n,left,mid,right);
    }
    return inversions;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long tmp[N];
    return mergeSort(arr,tmp,N,0,N-1);
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends