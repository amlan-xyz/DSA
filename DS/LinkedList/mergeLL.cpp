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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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

Node * mergeTwoSortedLinkedLists(Node *head1,Node * head2){

	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}

	Node * final_head=NULL;
	Node * final_tail=NULL;

	if(head1->data<head2->data){
		final_head=head1;
		final_tail=head1;
		head1=head1->next;
	}else{
		final_head=head2;
		final_tail=head2;
		head2=head2->next;
	}

	while(head1!=NULL && head2!=NULL){

		if(head2->data<head1->data){
			final_tail->next=head2;
			final_tail=head2;
			head2=head2->next;
		}else{
			final_tail->next=head1;
			final_tail=head1;
			head1=head1->next;
		}	
	}

	if(head1!=NULL){
		final_tail->next=head1;
	}
	if(head2!=NULL){
		final_tail->next=head2;
	}

	return final_head;
	
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}