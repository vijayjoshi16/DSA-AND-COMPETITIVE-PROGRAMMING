
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    
    bool isLeaf(Node* node){
        if(node==NULL)
        return false;
        return node->left==NULL && node->right==NULL;
    }
    
    bool isSumTree(Node* node)
    {
         // Your code here
         if(node==NULL || isLeaf(node))
         return true;
         if(isSumTree(node->left)&&isSumTree(node->right)){
             int ls,rs;
             if(node->left==NULL)
             ls=0;
             else if(isLeaf(node->left))
             ls=node->left->data;
             else
             ls=2*(node->left->data);
             
             if(node->right==NULL)
             rs=0;
             else if(isLeaf(node->right))
             rs=node->right->data;
             else
             rs=2*(node->right->data);
             
             return node->data == ls+rs;
         }
    }
};

// { Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}  // } Driver Code Ends