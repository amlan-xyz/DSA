#include <iostream>
#include "treeNode.h"
#include<queue>
using namespace std;

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int> * getNextLargerElement(TreeNode<int> * root,int x){
	if(root==NULL){
		return NULL;
	}

	TreeNode<int> *large=NULL;

	if(root->data>x){
		large=root;
	}

	for(int i=0;i<root->children.size();i++){
		TreeNode<int>* childLarge=getNextLargerElement(root->children[i],x);
		if(childLarge==NULL){
			continue;
		}else{
			if(large==NULL){
				large=childLarge;
			}else if(childLarge->data>x && childLarge->data<large->data){
				large=childLarge;
			}
		}
	}
	return large;
}


int main() {
   TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}