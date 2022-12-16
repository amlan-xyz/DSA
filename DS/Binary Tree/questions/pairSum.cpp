#include <iostream>
#include <queue>
#include<bits/stdc++.h>
#include "BinaryTreeNode.h"

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

void makeArray(BinaryTreeNode<int>*root,vector<int> &array_container){
	if(root==NULL){
		return;
	}
	array_container.push_back(root->data);
	makeArray(root->left,array_container);
	makeArray(root->right,array_container);
}

void pairSum(BinaryTreeNode<int>*root,int sum){

	vector<int> array_container;
	makeArray(root,array_container);
	sort(array_container.begin(),array_container.end());

	int i=0,j=array_container.size()-1;
	while(i<j){
		int start=array_container[i];
		int end=array_container[j];
		if(start+end==sum){
			cout<<start<<" "<<end<<endl;
			i++;j--;
		}else if(start+end>sum){
			j--;
		}else{
			i++;
		}
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}