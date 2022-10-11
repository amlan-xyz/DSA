//bubble sort iterative
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

int lengthLL(Node * head){
	int count=0;
	while(head!=NULL){
		head=head->next;
		count++;
	}
	return count;
}

Node *bubbleSort(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}

	for(int i=0;i<lengthLL(head)-1;i++){
		Node *prev=NULL;
		Node *curr=head;
		Node *nxt=curr->next;

		while(curr->next!=NULL){
			if(curr->data>curr->next->data){
				if(prev==NULL){
					curr->next=nxt->next;
					nxt->next=curr;
					prev=nxt;
					head=prev;
				}else{
					nxt=curr->next;
					curr->next=nxt->next;
					prev->next=nxt;
					nxt->next=curr;
					prev=nxt;
				}
			}else{
				prev=curr;
				curr=curr->next;
			}
		}
	}
	return head;
}

int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}