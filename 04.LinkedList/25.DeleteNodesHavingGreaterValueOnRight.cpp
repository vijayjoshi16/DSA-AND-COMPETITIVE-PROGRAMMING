#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node* curr=head,*tmp,*prev=NULL;
        while(curr){
            tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        head=prev;
        Node *maxNode=head;
        curr=head;
        tmp=NULL;
        while(curr&&curr->next){
            if(curr->next->data<maxNode->data){
                tmp=curr->next;
                curr->next=tmp->next;
                free(tmp);
            }else{
                curr=curr->next;
                maxNode=curr;
            }
        }
        tmp=NULL;
        curr=head;
        prev=NULL;
        while(curr){
            tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
        }
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends