#include<iostream>
#include<queue>
#include "treeNode.h"
#include<algorithm>
using namespace std;


TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter root data"<<endl;
	cin>>rootData;
	TreeNode<int> *root=new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		TreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter the number of children of "<<front->data<<endl;
		int childInput;
		cin>>childInput;
		for(int i=0;i<childInput;i++){
			int childData;
			cout<<"Enter "<<i<<" th child of "<<front->data<<endl;
			cin>>childData;
			TreeNode<int> *child=new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int> * takeInput(){
	int rootData;
	cout<<"Enter data"<<endl;
	cin>>rootData;
	TreeNode<int>* root=new TreeNode<int>(rootData);
	int n;
	cout<<"Enter number of children nodes of "<<rootData<<" "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		TreeNode<int>*child=takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++){
		cout<<root->children[i]->data<<", ";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printTree(root->children[i]);
	}
}

// print the tree level wise

void printLevelWise(TreeNode<int>* root){
	if(root==NULL){
		return ;
	}

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()){
		TreeNode<int> *front=pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<":";
		for(int i=0;i<front->children.size();i++){
			pendingNodes.push(front->children[i]);
			if(i==front->children.size()-1){
				cout<<front->children[i]->data;
			}else{
				cout<<front->children[i]->data<<",";
			}
			
		}
		cout<<endl;
	}
}

// count the number of nodes

int numOfNodes(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans+=numOfNodes(root->children[i]);
	}

	return ans;
}

// find the sum of nodes

int sumOfNodes(TreeNode<int>* root) {
    int ans=root->data;
	for(int i=0;i<root->children.size();i++){
		ans+=sumOfNodes(root->children[i]);
	}

	return ans;
}

// return the max node

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* maxNode=new TreeNode<int>(root->data);

	for(int i=0;i<root->children.size();i++){
		TreeNode<int>*childNode=maxDataNode(root->children[i]);
		if(childNode->data > maxNode->data){
			maxNode=childNode;
		}
	}
	return maxNode;

}


// height of the tree

int getHeight(TreeNode<int>* root) {
    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans = max(ans, 1 + getHeight(root->children[i]));
    }
   return ans;
}

// print nodes at level K

void printAtLevelK(TreeNode<int>* root,int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<endl;
		return;
	}

	for(int i=0;i<root->children.size();i++){
		printAtLevelK(root->children[i],k-1);
	}
}

// find the count of leaf nodes

int getLeafNodeCount(TreeNode<int>* root) {

	if(root==NULL){
		return 0;
	}

	int ans=0;

   if(root->children.size()==0){
		return 1;
   }

   for(int i=0;i<root->children.size();i++){
		ans+=getLeafNodeCount(root->children[i]);
   }

   return ans;
}

// pre order
// Algorithm Preorder(tree)

// Visit the root.
// Traverse the left subtree, i.e., call Preorder(left->subtree)
// Traverse the right subtree, i.e., call Preorder(right->subtree) 

void preOrder(TreeNode<int> * root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++){
		preOrder(root->children[i]);
   }
}

// post order
// Algorithm Postorder(tree)

// Traverse the left subtree, i.e., call Postorder(left->subtree)
// Traverse the right subtree, i.e., call Postorder(right->subtree)
// Visit the root


void postOrder(TreeNode<int> *root){
	if(root==NULL){
		return;
	}
	for(int i=0;i<root->children.size();i++){
		postOrder(root->children[i]);
   	}
   cout<<root->data<<" ";
}


// one way of deleting the tree
// the other way is using destructor
void deleteTree(TreeNode<int>* root){
	for(int i=0;i<root->children.size();i++){
		deleteTree(root->children[i]);
   	}

	delete root;
}

// 10 3 20 30 40 2 40 50 0 0 0 0 

int main(){
	// TreeNode<int>* root =new TreeNode<int>();
	// root.data=data;
	// or
	// TreeNode<int>* root=new TreeNode<int>(1);
	// TreeNode<int>* node1=new TreeNode<int>(2);
	// TreeNode<int>* node2=new TreeNode<int>(3);
	// root->children.push_back(node1);
	// root->children.push_back(node2);
	// printTree(root);

	// TreeNode<int>* root=takeInput();
	// taking input level wise
	TreeNode<int>* root=takeInputLevelWise();
	// printLevelWise(root);
	// cout<<sumOfNodes(root)<<endl;
	// cout<<maxDataNode(root)->data<<endl;
	// cout<<getHeight(root)<<endl;
	postOrder(root);
	
	// todo delete tree
	deleteTree(root);
	// or
	~TreeNode();

}