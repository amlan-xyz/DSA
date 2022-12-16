#include "BinaryTreeNode.h"
#include "BSTClass.h"
#include<bits/stdc++.h>
using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

class Pair{
	public:
		int minimum;
		int maximum;
		bool bst;
		int height;
};

Pair BST(BinaryTreeNode<int> *root){
	if(root==NULL){
		Pair obj;
		obj.minimum=INT_MAX;
		obj.maximum=INT_MIN;
		obj.bst=true;
		obj.height=0;
		return obj;
	}

	Pair leftAns=BST(root->left);
	Pair rightAns=BST(root->right);

	int minimum=min(root->data,min(leftAns.minimum,rightAns.minimum));
	int maximum=max(root->data,max(leftAns.maximum,rightAns.maximum));
	bool isBST=(root->data>leftAns.maximum) && (root->data<rightAns.minimum) && leftAns.bst && rightAns.bst;

	Pair ans;
	ans.minimum=minimum;
	ans.maximum=maximum;
	ans.bst=isBST;
	if(isBST){
		ans.height=1+max(leftAns.height,rightAns.height);
	}else{
		ans.height=max(leftAns.height,rightAns.height);
	}

	return ans;
}

int largestBSTSubtree(BinaryTreeNode<int>* root){
	return BST(root).height;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}