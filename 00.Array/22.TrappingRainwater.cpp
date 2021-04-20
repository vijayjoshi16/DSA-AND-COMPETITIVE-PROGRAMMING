#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   


// arr: input array
// n: size of array
// Function to find the trapped water between the blocks.
int trappingWater(int a[], int n){

    // Your code here
    int sum=0,lm=0,rm=0,lo=0,hi=n-1;
    while(lo<=hi){
        if(a[lo]<a[hi]){
            if(a[lo]>lm)
            lm=a[lo];
            else
            sum+=lm-a[lo];
            lo++;
        }else{
            if(a[hi]>rm)
            rm=a[hi];
            else
            sum+=rm-a[hi];
            hi--;
        }
    }
    return sum;
    
    
}

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends