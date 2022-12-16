#include <iostream>
using namespace std;
#include "BSTClass.h"


void insertDuplicateNode(BinaryTreeNode<int> *root){
    if(root==NULL){
        return ;
    }

    if(root->left!=NULL){
        BinaryTreeNode<int>*temp1=root->left;
        BinaryTreeNode<int>*temp2=new BinaryTreeNode<int>(root->data);
        root->left=temp2;
        temp2->left=temp1;
    }else{
        BinaryTreeNode<int> *temp=new BinaryTreeNode<int>(root->data);
        root->left=temp;
    }
    insertDuplicateNode(root->left->left);
    insertDuplicateNode(root->right);
}

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}