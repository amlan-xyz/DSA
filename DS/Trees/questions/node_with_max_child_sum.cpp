#include <iostream>
#include "treeNode.h"
#include<queue>
using namespace std;

TreeNode<int> * maxSumNode(TreeNode<int> *root){
    TreeNode<int> *ans=root;

    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }

    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *childMax=maxSumNode(root->children[i]);
        int smallSum=childMax->data;

        for(int i=0;i<childMax->children.size();i++){
            smallSum+=childMax->children[i]->data;
        }

        if(sum<=smallSum){
            ans=childMax;
            sum=smallSum;
        }
    }
    return ans;
}


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



int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}