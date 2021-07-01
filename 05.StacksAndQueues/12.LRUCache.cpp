#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    list<int> dq;
    unordered_map<int,list<int>::iterator> ma;
    unordered_map<int,int> val;
    int capacity;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(ma.find(key)==ma.end()){
            return -1;
        }else{
            auto it=ma[key];
            dq.erase(ma[key]);
            dq.push_front(key);
            ma[key]=dq.begin();
            return val[key];
        }
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        if(ma.find(key)!=ma.end()){
            auto it=ma[key];
            dq.erase(it);
            dq.push_front(key);
            ma[key]=dq.begin();
            val[key]=value;
        }else{
            if(dq.size()==capacity){
                int last=dq.back();
                ma.erase(last);
                dq.pop_back();
                dq.push_front(key);
                ma[key]=dq.begin();
                val[key]=value;
            }else{
                dq.push_front(key);
                ma[key]=dq.begin();
                val[key]=value;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends