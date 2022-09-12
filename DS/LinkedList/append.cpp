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

int lengthLL(Node *head){
	int count=0;
	while(head!=NULL){
		head=head->next;
        count++;
	}

	return count;
}

Node *appendLastNToFirst(Node * head,int n){
	
	int len=lengthLL(head);

	// corner cases if ll is null and 0 element needs to be shifted

	if(n==0 || len==0){
		return head;
	}

	int pos=len-n;

	Node *tail=head;
	int count=0;

	while(count<pos-1){
		tail=tail->next;
		count++;
	}

	Node *newHead=tail->next;
	tail->next=NULL;
	Node *newTail=newHead;

	count=pos;
	while(count<len-1){
		newTail=newTail->next;
		count++;
	}

	newTail->next=head;
	head=newHead;

	return head;


}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head=appendLastNToFirst(head, n);
		print(head);
		
	}
	return 0;
}