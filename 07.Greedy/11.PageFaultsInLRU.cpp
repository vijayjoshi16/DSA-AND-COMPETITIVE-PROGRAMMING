// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_set<int> page;
        list<int> q;
        int faults=0;
        for(int i=0;i<N;i++){
            if(page.size()==C){
                if(page.find(pages[i])==page.end()){
                    auto itr=q.begin();
                    page.erase(*itr);
                    page.insert(pages[i]);
                    q.erase(itr);
                    q.push_back(pages[i]);
                    faults++;
                }else{
                    auto itr=std::find(q.begin(),q.end(),pages[i]);
                    q.erase(itr);
                    q.push_back(pages[i]);
                }
            }else{
                if(page.find(pages[i])==page.end()){
                    page.insert(pages[i]);
                    q.push_back(pages[i]);
                    faults++;
                }else{
                    auto itr=std::find(q.begin(),q.end(),pages[i]);
                    q.erase(itr);
                    q.push_back(pages[i]);
                }
            }
        }
        return faults;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends