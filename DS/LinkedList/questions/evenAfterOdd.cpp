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

Node * evenAfterOdd(Node *head){
	Node * curr=head;
	Node * even_head=NULL;
	Node *even_tail=NULL;
	Node *odd_head=NULL;
	Node *odd_tail=NULL;

	if(head==NULL || head->next==NULL){
		return head;
	}

	while(curr!=NULL){
		if(curr->data%2!=0){
			if(odd_head==NULL){
				odd_head=curr;
				odd_tail=curr;
			}else{
				odd_tail->next=curr;
				odd_tail=curr;
			}
		}else{
			if(even_head==NULL){
				even_head=curr;
				even_tail=curr;
			}else{
				even_tail->next=curr;
				even_tail=curr;
			}
		}
		curr=curr->next;
	}
	if(even_tail!=NULL){
		even_tail->next=NULL;
	}
	if(odd_head==NULL){
		return even_head;
	}else{
		odd_tail->next=even_head;
		return odd_head;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}