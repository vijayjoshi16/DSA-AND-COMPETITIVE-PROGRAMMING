#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
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
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
bool ans;
unordered_set<string> s;

string dupSubUtil(Node *root){
    vector<int> v;
    if(root==NULL)
    return "";
    string a1=dupSubUtil(root->left);
    string a2=dupSubUtil(root->right);
    string a3=a1+to_string(root->data)+a2;
    if(a3.length()>=2){
        if(s.find(a3)==s.end()){
            s.insert(a3);
        }else{
            ans=true;
        }
    }
    return a3;
}

bool dupSub(Node *root)
{
     //your code here
     ans=false;
     s.clear();
     dupSubUtil(root);
     return ans;
}

// { Driver Code Starts.
int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		//Solution ob;
		cout << dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends