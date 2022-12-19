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

bool areIdentical(TreeNode<int> *root1,TreeNode<int> *root2){
	if(root1->data!=root2->data){
		return false;
	}

	if(root1->children.size()!=root2->children.size()){
		return false;
	}

	bool ans=true;

	for(int i=0;i<root1->children.size();i++){
		bool smallAns=areIdentical(root1->children[i],root2->children[i]);

		if(smallAns==false){
			ans=false;
			return ans;
		}
	}
	return ans;
}

int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}