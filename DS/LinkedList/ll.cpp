#include<iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput(){
	int data;
	cin>>data;
	Node *head=NULL;
	Node *tail=NULL;
	while(data!=-1){
		Node *newNode=new Node(data);
		if(head==NULL){
			head=newNode;
			tail=newNode;
		}else{
			// Node *temp=head;
			// while(temp->next!=NULL){
			// 	temp=temp->next;
			// }
			// temp->next=newNode;

			// or

			tail->next=newNode;
			tail=tail->next;
		}
		cin>>data;
	}
	return head;
}

void print(Node *head){
	Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}

Node* insertNode(Node* head,int i,int data){
	Node* newNode=new Node(data);
	int count=0;
	Node *temp=head;

	if(i==0){
		newNode->next=head;
		head=newNode;
		return head;
	}

	while(temp!=NULL && count<i-1){
		temp=temp->next;
		count++;
	}
	if(temp!=NULL){
		Node *a=temp->next;
		temp->next=newNode;
		newNode->next=a;
	}

	return head;
}

Node * deleteNode(Node *head,int pos){

	Node* temp=head;

	int count=0;

	if(head==NULL){
		return head;
	}

	if(pos==0){
		head=temp->next;
		delete temp;
	}

	while(temp!=NULL && count<pos-1){
		temp=temp->next;
		count++;
	}

	if(temp==NULL){
		return head;
	}

	if(temp->next!=NULL){
		temp->next=temp->next->next;
	}

	return head;

}

// length recursive

int length(Node* head){

	if(head==NULL){
		return 0;
	}	

	return 1+ length(head->next);
}

Node *insertNodeRecursively(Node* head,int i,int data){

	if(head==NULL){
		return NULL;
	}

	if(i==0){
		Node* temp=new Node(data);
		temp->next=head;
		return temp;
	}

	if(i==1){
		Node* temp=new Node(data);
		temp->next=head->next;
		head->next=temp;
		return head;
	}

	Node * curr=insertNodeRecursively(head->next,i-1,data);
	return head;

}

Node *deleteNodeRecursively(Node* head,int i){

	if(head->next==NULL){
		return NULL;
	}

	if(i==0){
		Node *temp=head->next;
		head->next=NULL;
		delete head;
		return temp;
	}

	if(i==1){
		Node * temp=head->next;
		head->next=temp->next;
		temp->next=NULL;
		delete temp;
		return head;
	}

	Node * curr=deleteNodeRecursively(head->next,i-1);
	return head;

}

Node * insertFront(Node* head,int data){

	Node * newNode=new Node(data);
	newNode->next=head;
	head=newNode;

	return head;
}

Node *insertEnd(Node* head, int data){
	Node* curr=head;
	while(curr->next!=NULL){
		curr=curr->next;
	}

	Node *newNode=new Node(data);
	curr->next=newNode;
	newNode->next=NULL;
	return head;
}

Node *inserAtPos(Node * head,int pos,int data){
	Node *curr=head;
	Node *newNode=new Node(data);

	if(pos==0){
		insertFront(curr,data);
	}

	int count=0;

	while(curr->next!=NULL && count<pos-1){
		curr=curr->next;
		count++;
	}

	if(curr->next==NULL){
		curr->next=newNode;
		newNode->next=NULL;
		return head;
	}

	Node *temp=curr->next;
	curr->next=newNode;
	newNode->next=temp;

	return head;
}

int main(){

	Node *head=takeInput();
	print(head);
	// int i,data;
	// cin>>i>>data;
	// head=insertNode(head,i,data);
	// print(head);
	// head=deleteNode(head,3);
	// head=insertFront(head,0);
	// print(head);
	// head=insertEnd(head,100);
	// print(head);
	// head=inserAtPos(head,3,88);
	int pos, data;
    cin >> pos >> data;
    head = insertNodeRecursively(head, pos, data);
    print(head);
}