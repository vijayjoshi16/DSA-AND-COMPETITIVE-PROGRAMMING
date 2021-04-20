//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends

int median(int arr[],int n){
    sort(arr,arr+n);
    return(arr[n/2]);
}

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int getPartition(int arr[],int l,int r,int x){
    int ind;
    for(ind=l;ind<r;ind++)
    if(arr[ind]==x)
    break;
    swap(&arr[ind],&arr[r]);
    int i=l;
    for(int j=l;j<r;j++){
        if(arr[j]<=x){
            swap(&arr[j],&arr[i]);
            i++;
        }
    }
    swap(&arr[r],&arr[i]);
    return i;
}

//User function template for C++


// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    if(k>0&&k<=(r-l+1)){
        int n = r-l+1;
        int i;
        int med[(n+4)/5];
        for(i=0;i<n/5;i++){
            med[i]=median(arr+i*5+l,5);
        }
        if(i*5<n){
            med[i]=median(arr+l+i*5,n%5);
            i++;
        }
        int medianOfMedians = i==1?med[0]:kthSmallest(med,0,i-1,(i)/2);
        int position = getPartition(arr,l,r,medianOfMedians);
        
        if(position-l == k-1){
        return arr[position];
        }else{
            if(position-l>k-1){
                return kthSmallest(arr,l,position-1,k);
            }else{
                return kthSmallest(arr,position+1,r,k-(position+1)+l);
            }
        }
    }
    return INT_MAX;
}