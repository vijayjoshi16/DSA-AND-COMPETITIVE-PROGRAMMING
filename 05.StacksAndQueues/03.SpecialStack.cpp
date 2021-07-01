// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

int minElement;

void push(stack<int>& s, int a){
	// Your code goes here
	if(s.size()!=0){
	    if(a<minElement){
	        s.push(2*a-minElement);
	        minElement=a;
	    }else{
	        s.push(a);
	    }
	}else{
	    s.push(a);
	    minElement=a;
	}
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
    return s.size()==n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.size()==0;
}

int pop(stack<int>& s){
	// Your code goes here
	int ans;
	if(s.top()>minElement){
	    ans = s.top();
	}else{
	    ans=minElement;
	    minElement=2*minElement-s.top();
	}
	s.pop();
	return ans;
}

int getMin(stack<int>& s){
	// Your code goes here
	return minElement;
}