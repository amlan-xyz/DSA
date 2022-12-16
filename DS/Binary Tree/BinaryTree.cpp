#include<bits/stdc++.h>
#include "BinaryTreeNode.h"


using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};


BinaryTreeNode<int> * takeInput(){
	int rootData;
	cout<<"Enter data"<<endl;
	cin>>rootData;
	if(rootData==-1){
		return NULL;
	}

	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int> * leftChild=takeInput();
	BinaryTreeNode<int> * rightChild=takeInput();
	root->left=leftChild;
	root->right=rightChild;
}

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter root data"<<endl;
	cin>>rootData;
	if(rootData==-1){
		return NULL;
	}

	BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>* > pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter left child of"<<front->data<<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData!=-1){
			BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChildData);
			front->left=child;
			pendingNodes.push(child);
		}

		cout<<"Enter right child "<<front->data<<endl;
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData!=-1){
			BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChildData);
			front->right=child;
			pendingNodes.push(child);
		}
	}
	return root;
}

void printTree(BinaryTreeNode<int> * root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" : ";
	if(root->left){
		cout<<"L"<<root->left->data;
	}
	cout<<" ";
	if(root->right){
		cout<<"R"<<root->right->data;
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}

void printLevelWise(BinaryTreeNode<int> * root){
	
	if(root==NULL){
		return;
	}

	queue<BinaryTreeNode<int>* >pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()){
		BinaryTreeNode<int> * front=pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<":";
		if(front->left){
			pendingNodes.push(front->left);
			cout<<"L:"<<front->left->data;
		}else{
			cout<<"L:-1";
		}
		cout<<",";

		if(front->right){
			pendingNodes.push(front->right);
			cout<<"R:"<<front->right->data;
		}else{
			cout<<"R:-1";
		}
		cout<<endl;
	}
}

int countNodes(BinaryTreeNode<int>*root){
	if(root==NULL){
		return 0;
	}
	return 1+countNodes(root->left)+countNodes(root->right);
}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
	bool ans=false;

    if(root->data==x){
		ans=true;
	}

	if(root->left){
		bool leftAns=isNodePresent(root->left,x);
		if(leftAns){
			ans=leftAns;
		}
	}

	if(root->right){
		bool rightAns=isNodePresent(root->right,x);
		if(rightAns){
			ans=rightAns;
		}
	}
	
	return ans;

}

int height(BinaryTreeNode<int>*root){
	// int h=0;
	// if(root==NULL){
	// 	return h;
	// }

	// int leftHeight=height(root->left);
	// int rightHeight=height(root->right);

	// if(leftHeight>rightHeight){
	// 	return leftHeight+1;
	// }else{
	// 	return rightHeight+1;
	// }

	if(root==NULL){
		return 0;
	}

	return 1+max(height(root->left),height(root->right));
}


void mirrorBinaryTree(BinaryTreeNode<int>* root) {
   if(!root)
       return;
    BinaryTreeNode<int>* temp=root->left;
    
    root->left=root->right;
    root->right=temp;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    

}

void inorder(BinaryTreeNode<int>* root){
	if(root==NULL){
		return ;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void  preorder(BinaryTreeNode<int>*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postOrder(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

BinaryTreeNode<int>* buildTreeHelper(int *in,int *pre, int inorderStart,int inorderEnd,int preorderStart,int preorderEnd){
	if(inorderStart>inorderEnd){
		return NULL;
	}

	int rootData=pre[preorderStart];
	int rootIdx=-1;
	for(int i=inorderStart;i<=inorderEnd;i++){
		if(in[i]==rootData){
			rootIdx=i;
			break;
		}
	}

	int leftInorderStart=inorderStart;
	int leftInorderEnd=rootIdx-1;
	int leftPreorderStart=preorderStart+1;
	int leftPreorderEnd=leftInorderEnd-leftInorderStart+leftPreorderStart;
	int rightPreorderStart=leftInorderEnd+1;
	int rightPreorderEnd=preorderEnd;
	int rightInorderStart=rootIdx+1;
	int rightInorderEnd=inorderEnd;
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
	root->left=buildTreeHelper(in,pre,leftInorderStart,leftInorderEnd,leftPreorderStart,leftPreorderEnd);
	root->right=buildTreeHelper(in,pre,rightInorderStart,rightInorderEnd,rightPreorderStart,rightPreorderEnd);
	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return buildTreeHelper(inorder,preorder,0,inLength-1,0,preLength-1);
}

// pair sum 

//O(n*n)

// bool findPair(BinaryTreeNode<int> *root,int node_value){
// 	if(root==NULL){
// 		return false;
// 	}

// 	if(root->data==node_value){
// 		// root->data=INT_MIN;
// 		return true;
// 	}

// 	return findPair(root->left,node_value)||findPair(root->right,node_value);
// }

// void printPair(BinaryTreeNode<int> *curr_node,int sum,BinaryTreeNode<int> * root){
// 	if(curr_node==NULL){
// 		return;
// 	}

// 	if(curr_node->data!=INT_MIN){
// 		bool isPair = findPair(root,sum-curr_node->data);
// 		if(isPair&& curr_node->data != sum - curr_node->data){
// 			if(curr_node->data<sum-curr_node->data)
// 			{
// 				cout << curr_node->data << " " << sum - curr_node->data<<endl;
// 			}
// 			else
// 			{
// 				cout <<  sum - curr_node->data << " " <<curr_node->data<<endl;
// 			}
                
//         }
// 		curr_node->data=INT_MIN;
// 	}

// 	printPair(curr_node->left,sum,root);
// 	printPair(curr_node->right,sum,root);
// }

// void pairSum(BinaryTreeNode<int> *root, int sum) {
//     // Write your code here

// 	if(root==NULL){
// 		return;
// 	}

// 	printPair(root,sum,root);
// }

// optimized approach

// post order and inorder

BinaryTreeNode<int>* tree(int *postorder, int *inorder,int ps,int pe, int is, int ie)
{
    if(ps>pe)
        return NULL;
    
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(postorder[pe]);
    
     int k = 0; 
    for(int i = is; i <= ie; i++)
    { if(postorder[pe] == inorder[i])
        { k = i; break; } 
    }
    
    int lps=ps;    //left prestart
    int lis=is;  //left instart
    int  lie=k-1;   //left inend
    int lpe= lie-lis+lps; //left  pre end
    
    int rps=lpe+1; //right prestart
    int rpe=pe-1;//  right preend
    int ris=k+1;  //right instart
    int rie=ie;   //right inend
    
    root->left=tree(postorder,inorder,lps,lpe,lis,lie);
    root->right=tree(postorder,inorder,rps,rpe,ris,rie);
    
    return root;
    
    
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    return tree (postorder,inorder,0,postLength-1,0,inLength-1);

}

// diameter of a tree

int diameter(BinaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	
	int option1=height(root->left)+height(root->right);
	int option2=diameter(root->left);
	int option3=diameter(root->right);

	return max(option1,max(option2,option3));
}	

// optimized O(n) 

pair<int,int> heightDiameter(BinaryTreeNode<int> * root){
	if(root==NULL){
		pair<int,int> p;
		p.first=0;
		p.second=0;
		return p;
	}

	pair<int,int> leftAns=heightDiameter(root->left);
	pair<int,int> rightAns=heightDiameter(root->right);
	int ld=leftAns.second;
	int lh=leftAns.first;
	int rd=rightAns.second;
	int rh=rightAns.first;

	int height=1+max(lh,rh);
	int diameter=max(lh+rh,max(ld,rd));
	pair<int,int> p;
	p.first=height;
	p.second=diameter;
	return p;
}

// min and max node
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	pair<int,int> p={INT_MAX,INT_MIN};

	if(root==NULL){
		return p;
	}

	pair<int,int> rootVal={root->data,root->data};
	pair<int,int> leftVal=getMinAndMax(root->left);
	pair<int,int> rightval=getMinAndMax(root->right);
	rootVal.first=min(rootVal.first,min(leftVal.first,rightval.first));
	rootVal.second=max(rootVal.second,max(leftVal.second,rightval.second));
	return rootVal;
}


// questions

// 1. sum of the nodes

int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
	if(root==NULL){
		return 0;
	}

	return root->data+getSum(root->left)+getSum(root->right);
}

// balanced binary tree

bool isBalanced(BinaryTreeNode<int> *root) {
	if(root==NULL){
		return true;
	}

	int leftHeight=height(root->left);
	int rightHeight=height(root->right);
	

	if((abs(leftHeight-rightHeight)==0 || abs(leftHeight-rightHeight)==1) && isBalanced(root->left)&& isBalanced(root->right)){
		return true;
	}

	return false;
}

// 

void levelOrder(BinaryTreeNode<int> *root) {
    
	if(root==NULL){
		return;
	}

	queue<BinaryTreeNode<int>* >pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);

	while(!pendingNodes.empty()){

		BinaryTreeNode<int> * front=pendingNodes.front();
		pendingNodes.pop();
		if(front==NULL){
			if(pendingNodes.empty()){
				break;
			}
			cout<<endl;
			pendingNodes.push(NULL);
		}else{
			cout<<front->data<<" ";
			if(front->left){
				pendingNodes.push(front->left);
			}
			if(front->right){
				pendingNodes.push(front->right);
			}
		}
		
	}	
}
// remove leaf nodes
BinaryTreeNode<int> * removeLeafNodes(BinaryTreeNode<int> * root){
	if(root==NULL || (root->left==NULL && root->right==NULL)){
		return NULL;
	}

	if(root->left!=NULL){
		root->left=removeLeafNodes(root->left);
	}

	if(root->right!=NULL){
		root->right=removeLeafNodes(root->right);
	}

	return root;
}

// construct linked list level wise

vector<Node<int> *> constructLinkedListforEachLevel(BinaryTreeNode<int> *root){
	vector<Node<int> *> v={NULL};
	if(root==NULL){
		return v;
	}else{
		v.clear();
	}

	queue<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		int n=pendingNodes.size();
		Node<int> *head=NULL;
		Node<int> *tail=NULL;
		while(n!=0){
			BinaryTreeNode<int> *front=pendingNodes.front();
			pendingNodes.pop();
			Node<int> *newNode=new Node<int>(front->data);
			if(head==NULL){
				head=newNode;
				tail=newNode;
			}else{
				tail->next=newNode;
				tail=newNode;
			}

			if(front->left){
				pendingNodes.push(front->left);
			}

			if(front->right){
				pendingNodes.push(front->right);
			}

			n--;
		}
		v.push_back(head);
	}
	return v;
}

// zig zag traversal

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL){
		return;
	}	

	vector<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push_back(root);

	int level=1;
	while(!pendingNodes.empty()){
		int n=pendingNodes.size();
		if(level%2==0){
			//right->left
			for(int i=n-1;i>=0;i--){
				cout<<pendingNodes[i]->data<<" ";
			}
		}else{
			for(auto i : pendingNodes){
				cout<<i->data<<" ";
			}
		}

		for(int i=0;i<n;i++){
			BinaryTreeNode<int> *front=pendingNodes[i];
			if(front->left!=NULL){
				pendingNodes.push_back(front->left);
			}
			if(front->right){
				pendingNodes.push_back(front->right);
			}
		}
		pendingNodes.erase(pendingNodes.begin(), pendingNodes.begin() + n);
        cout << "\n";
        level++;
	}
}

// nodes without sibling

void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    if (root->left != NULL && root->right == NULL)
        cout << root->left->data << " ";
    else if (root->left == NULL && root->right != NULL)
        cout << root->right->data << " ";
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main(){

	// BinaryTreeNode<int> * root=new BinaryTreeNode<int>(1);
	// BinaryTreeNode<int> * node1=new BinaryTreeNode<int>(2);
	// BinaryTreeNode<int> * node2=new BinaryTreeNode<int>(3);
	// root->left=node1;
	// root->right=node2;

	BinaryTreeNode<int>* root=takeInputLevelWise();
	int sum;
    cin >> sum;
    pairSum(root, sum);
	delete root;
}