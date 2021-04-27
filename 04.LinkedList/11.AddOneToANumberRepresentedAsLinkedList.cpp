//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    int addWithCarry(Node *head){
        int carry;
        if(head->next==NULL){
            //cout<<"x";
            if(head->data<=8){
                head->data=head->data+1;
                carry=0;
            }else{
                head->data=0;
                carry=1;
            }
        }else{
            carry=addWithCarry(head->next);
            //cout<<"y";
            if(carry==1){
                if(head->data<=8){
                    head->data=head->data+1;
                    carry=0;
                }else{
                    head->data=0;
                    carry=1;
                }
            }
        }
        return carry;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int finalCarry = addWithCarry(head);
        Node *tmp=new Node(1);
        if(finalCarry==1){
            tmp->data=1;
            tmp->next=head;
            return tmp;
        }
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends