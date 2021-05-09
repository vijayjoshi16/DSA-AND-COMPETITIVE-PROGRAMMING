//Initial Template for C++
#include <bits/stdc++.h>
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


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
int maxLevel;
int maxSum;


void sumOfLongest(Node *root,int sum,int level){
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL){
        if(level>maxLevel){
            maxLevel=level;
            maxSum=sum+root->data;
        }else if(maxLevel==level){
            if(sum+root->data>maxSum)
            maxSum=sum+root->data;
        }
    }else{
        sumOfLongest(root->left,sum+root->data,level+1);
        sumOfLongest(root->right,sum+root->data,level+1);
    }
}

// your task is to complete this function
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	maxLevel=0;
	maxSum=0;
	sumOfLongest(root,0,0);
	return maxSum;
}