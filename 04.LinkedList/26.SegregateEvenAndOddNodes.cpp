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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *tmp=head;
        Node *evenHead=NULL,*oddHead=NULL;
        Node *tmpe=NULL,*tmpo=NULL;
        while(tmp){
            int d=tmp->data;
            if(d%2==0){
                if(evenHead!=NULL){
                    tmpe->next=new Node(d);
                    tmpe=tmpe->next;;
                }else{
                    evenHead=new Node(d);
                    tmpe=evenHead;
                }
            }else{
                if(oddHead!=NULL){
                    tmpo->next=new Node(d);
                    tmpo=tmpo->next;
                }else{
                    oddHead=new Node(d);
                    tmpo=oddHead;
                } 
            }
            tmp=tmp->next;
        }
        if(tmpe!=NULL){
            tmpe->next=oddHead;
            return evenHead;  
        }else{
            return oddHead;
        }
        
    }    
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends