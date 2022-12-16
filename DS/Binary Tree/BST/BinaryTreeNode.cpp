#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"


using namespace std;

template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

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

bool searchInBST(BinaryTreeNode<int> *root,int k){
    // Write your code here
    if (root == NULL)
        return false;
    if (root->data < k)
        searchInBST(root->right, k);
    else if (root->data > k)
        searchInBST(root->left, k);
    else if (root->data == k)
        return true;
}

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    // Write your code here
    if (root == NULL)
        return;
    if (k1 < root->data && k2 < root->data)
        elementsInRangeK1K2(root->left, k1, k2);
    else if (k1 > root->data && k2 > root->data)
        elementsInRangeK1K2(root->right, k1, k2);
    else if (k1 <= root->data && k2 >= root->data)
    {
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
}

// here special case time complexity is O(n^2);

int minimum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

int maximum(BinaryTreeNode<int> * root){
    if(root==NULL){
        return INT_MIN;
    }

    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }

    int leftMax=maximum(root->left);
    int rightMin=minimum(root->right);
    bool output=(root->data>leftMax) && (root->data<=rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

// optimized

class isBSTReturn{
    public:
        bool isBST;
        int minimum;
        int maximum;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root){
    if(root==NULL){
        isBSTReturn output;
        output.isBST=true;
        output.minimum=INT_MAX;
        output.minimum=INT_MIN;
        return output; 
    }

    isBSTReturn leftOutput=isBST2(root->left);
    isBSTReturn rightOutput=isBST2(root->right);
    int minimum=min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum=max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal=(root->data >leftOutput.maximum) && (root->data <=rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    isBSTReturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBSTFinal;
    return output;
}

BinaryTreeNode<int>* helper(int *input,int start,int end){

   if(start>end){
    return NULL;
   }

    int mid=(start+end)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    root->left=helper(input,start,mid-1);
    root->right=helper(input,mid+1,end);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    return helper(input,0,n-1);
}

// bst to sorted ll

class Pair{
    public:
        Node<int>*head;
        Node<int>* tail;
};

Pair BST(BinaryTreeNode<int> *root){
    if(root==NULL){
        Pair ans;
        ans.head=NULL;
        ans.tail=NULL;
        return  ans;
    }

    Node<int> *node =new Node<int>(root->data);

    Pair leftAns=BST(root->left);
    Pair rightAns=BST(root->right);

    Pair ans;

    if(leftAns.head==NULL && rightAns.head==NULL){
        ans.head=node;
        ans.tail=node;
    }else if(!leftAns.head && rightAns.head){
        ans.head=node;
        node->next=rightAns.head;
        ans.tail=rightAns.tail;
    }else if (leftAns.head && rightAns.head == NULL){
        ans.head = leftAns.head;
        leftAns.tail->next = node;
        ans.tail = node;
    }else{
        ans.head = leftAns.head;
        leftAns.tail->next = node;
        node->next = rightAns.head;
        ans.tail = rightAns.tail;
    }
    return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    return BST(root).head;
}

// root to path
vector<int> * getRootToNodePath(BinaryTreeNode<int>* root,int data){
    if(root==NULL){
        return NULL;
    }

    if(root->data==data){
        vector<int> *output=new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput=getRootToNodePath(root->left,data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput=getRootToNodePath(root->right,data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{
        return NULL;
    }
}
int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<int>*output=getRootToNodePath(root,8);
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<endl;
    }
    delete root;
}