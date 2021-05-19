#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int largestBst(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

int largestBSTUtil(Node *root,int *min_ref,int *max_ref,int *max_size_ref,bool *is_bst_ref){
    if(root==NULL){
        *is_bst_ref=true;
        return 0;
    }
    
    int min=INT_MAX;
    int ls,rs;
    bool lf=false,rf=false;
    *max_ref=INT_MIN;
    ls=largestBSTUtil(root->left,min_ref,max_ref,max_size_ref,is_bst_ref);
    if(*is_bst_ref&&root->data>*max_ref)
    lf=true;
    min=*min_ref;
    *min_ref=INT_MAX;
    rs=largestBSTUtil(root->right,min_ref,max_ref,max_size_ref,is_bst_ref);
    if(*is_bst_ref&&root->data<*min_ref)
    rf=true;
    if(min<*min_ref)
    *min_ref=min;
    if(root->data>*max_ref)
    *max_ref=root->data;
    if(root->data<*min_ref)
    *min_ref=root->data;
    if(lf&&rf){
        if(ls+rs+1>*max_size_ref)
        *max_size_ref=ls+rs+1;
        return 1+ls+rs;
    }else{
        *is_bst_ref=false;
        return 0;
    }
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
	//Your code here
	int min=INT_MAX;
	int max=INT_MIN;
	int max_size=0;
	bool  isBST=false;
	largestBSTUtil(root,&min,&max,&max_size,&isBST);
	return max_size;
}