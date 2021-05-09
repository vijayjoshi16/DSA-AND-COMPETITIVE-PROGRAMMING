//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    map<int,int> m;
    int preInd;
    public:
    
    Node* buildTreeUtil(int in[],int pre[],int inStart,int inEnd,int n){
        if(inStart>inEnd)
        return NULL;
        int curr=pre[preInd++];
        Node *tmp=new Node(curr);
        if(inStart==inEnd)
        return tmp;
        int inIndex = m[curr];
        tmp->left=buildTreeUtil(in,pre,inStart,inIndex-1,n);
        tmp->right=buildTreeUtil(in,pre,inIndex+1,inEnd,n);
        return tmp;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        m.clear();
        preInd=0;
        for(int i=0;i<n;i++)
        m[in[i]]=i;
        return buildTreeUtil(in,pre,0,n-1,n);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends