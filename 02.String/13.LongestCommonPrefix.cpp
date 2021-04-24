class Solution {
public:
    string longestPrefix(string s1,string s2){
        int n1=s1.length(),n2=s2.length();
        string str="";
        for(int i=0;i<min(n1,n2);i++){
            if(s1[i]==s2[i])
                str+=s1[i];
            else
                break;
        }
        return str;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()>=2){
            string str=longestPrefix(strs[0],strs[1]);
            for(int i=2;i<strs.size();i++){
                if(str.length()==0)
                    break;
                str=longestPrefix(str,strs[i]);
            }
            return str;
        }else{
            if(strs.size()==1)
                return strs[0];
            else
                return "";
        }
        
        
    }
};