#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
#include<vector>
using namespace std;


BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

void rootToLeafSumToK(BinaryTreeNode<int>*root,int k,vector<int>path){
	if(root==NULL){
		return ;
	}

	path.push_back(root->data);
	k=k-root->data;
	if(!root->left && !root->right){
		if(k==0){
			for(int i:path){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		path.pop_back();
		return;
	}

	rootToLeafSumToK(root->left,k,path);
	rootToLeafSumToK(root->right,k,path);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int> v;
    rootToLeafSumToK(root, k, v);
    return;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}