#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node *zero=new Node(0),*one = new Node(0),*two=new Node(0);
        Node *tmp0=zero,*tmp1=one,*tmp2=two;
        Node *tmp=head;
        while(tmp){
            if(tmp->data==0){
                tmp0->next=tmp;
                tmp0=tmp0->next;
            }else if(tmp->data==1){
                tmp1->next=tmp;
                tmp1=tmp1->next;
            }else{
                tmp2->next=tmp;
                tmp2=tmp2->next;
            }
            tmp=tmp->next;
        }
        tmp0->next=one->next?one->next:two->next;
        tmp1->next=two->next;
        tmp2->next=NULL;
        head=zero->next;
        delete zero;
        delete one;
        delete two;
        return head;
        
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends