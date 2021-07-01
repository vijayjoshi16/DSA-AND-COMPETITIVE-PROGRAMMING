#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// you are required to complete this function
// function should return the size of the 
// Largest Independent set in the tree


//User function template for C++

struct NNode
{
    int data;
    struct NNode* left;
    struct NNode* right;
    int liss;
    NNode(int x){
        data = x;
        left = right = NULL;
        liss=0;
    }
};

NNode *buildNTree(Node *root){
    if(root==NULL)
    return NULL;
    NNode *n=new NNode(root->data);
    n->left=buildNTree(root->left);
    n->right=buildNTree(root->right);
    return n;
}

int LISSUtil(NNode *root){
    if(root==NULL)
    return 0;
    if(root->liss)
    return root->liss;
    
    if(root->left==NULL&&root->right==NULL){
        root->liss=1;
        return root->liss;
    }
    
    //EXCLUDING CURRENT NODE
    int liss_exc=LISSUtil(root->left)+LISSUtil(root->right);
    
    //INCLUDING CURRENT NODE
    int liss_incl=1;
    
    if(root->left)
    liss_incl+=LISSUtil(root->left->left)+LISSUtil(root->left->right);
    if(root->right)
    liss_incl+=LISSUtil(root->right->left)+LISSUtil(root->right->right);
    
    root->liss=max(liss_exc,liss_incl);
    return root->liss;
}

int LISS(Node *root)
{
    //Code here
    NNode *nroot=buildNTree(root);
    return LISSUtil(nroot);
}


// { Driver Code Starts.
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
    string treeString;
	getline(cin,treeString);
	Node* root = buildTree(treeString);
    cout<<LISS(root)<<endl;
  }
  return 0;
}
  // } Driver Code Ends