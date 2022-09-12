#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void FindMiddle(Node * curr,Node **first,Node **second){
	Node *fast;
	Node *slow;
	slow=curr;
	fast=curr->next;

	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}

	*first=curr;
	*second=slow->next;
	slow->next=NULL;
}

Node * mergeBoth(Node *first,Node *second){
	Node *ans=NULL;

	if(!first){
		return second;
	}else if(!second){
		return first;
	}

	if(first->data<=second->data){
		ans=first;
		ans->next=mergeBoth(first->next,second);
	}else{
		ans=second;
		ans->next=mergeBoth(first,second->next);
	}

	return ans;
}

void mergeSorting(Node** head){
	Node * curr=*head;
	Node * first;
	Node * second;

	if(!curr || !curr->next) return;

	FindMiddle(curr,&first,&second);
	mergeSorting(&first);
	mergeSorting(&second);
	*head=mergeBoth(first,second);
}



Node * mergeSort(Node * head){
	mergeSorting(&head);
	return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}