// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.
class Solution {
public:
    string countAndSay(int n) {
        string s= "1";
        for(int i=1;i<n;i++){
            string tmp="";
            int ctr=0;
            for(int i=0;i<s.length();i++){
                ctr++;
                int j=i+1;
                while(s[j]==s[i]){
                    ctr++;
                    j++;
                }
                tmp+=to_string(ctr)+s[i];
                ctr=0;
                i=j-1;
            }
            s=tmp;
        }
        return s;
    }
};