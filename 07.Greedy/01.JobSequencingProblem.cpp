// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool compareJobs(const Job &j1,const Job &j2){
        return j1.profit>j2.profit;
    }
    
    int find(int i,int *parent){
        if(parent[i]==i)
        return i;
        parent[i]=find(parent[i],parent);
        return parent[i];
    }
    
    void merge(int u,int v,int *parent){
        parent[v]=u;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compareJobs);
        
        //ANSERR VECTOR TO RETURN
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(0);
                
        //FIND THE MAX DEADLINE
        int maxd=INT_MIN;
        for(int i=0;i<n;i++)
        maxd=max(maxd,arr[i].dead);
        
        int parent[maxd+1];
        for(int i=0;i<maxd+1;i++)
        parent[i]=i;
        
        for(int i=0;i<n;i++){
            int availableSlot=find(arr[i].dead,parent);
            if(availableSlot>0){
                ans[0]++;
                ans[1]+=arr[i].profit;
                merge(find(availableSlot-1,parent),availableSlot,parent);
            }
        }
        
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends