//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& s) 
{
    // Your Code Here
    map<map<char,int>,vector<string>> m;
    for(int i=0;i<s.size();i++){
        map<char,int> tmp;
        for(int j=0;j<s[i].length();j++){
            tmp[s[i][j]]++;
        }
        if(m.find(tmp)!=m.end()){
            m[tmp].push_back(s[i]);
        }else{
            vector<string> t;
            t.push_back(s[i]);
            m.insert({tmp,t});
        }
    }
    vector<vector<string>> result;

    for(auto it = m.begin();
             it != m.end(); ++it)
    {
        result.push_back(it->second);
    }
    return result;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends