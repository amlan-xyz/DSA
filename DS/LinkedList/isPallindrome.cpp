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

Node * reverse(Node * head){
	Node *curr=head;
	Node * prev=NULL, *next=NULL;

	while(curr!=NULL){
		// store next
		next=curr->next;

		// reverse curr
		curr->next=prev;

		// move pointer
		prev=curr;
		curr=next;
	}
	head=prev;
}

bool isPalindrome(Node * head){

	if(head==NULL || head->next==NULL){
		return true;
	}

	Node * curr=head;

	int count=0;

	while(curr!=NULL){
		count++;
		curr=curr->next;
	}

	int mid=(count/2)-1;
	int pos=0;
		curr=head;
		while(pos<mid-1){
			curr=curr->next;
			pos++;
		}

	if(count%2==0){
		
		Node *newHead=reverse(curr->next);
		curr=head;
		while(curr!=NULL){
			if(curr->data!=newHead->data){
				return false;
			}
			curr=curr->next;
			newHead=newHead->next;
		}
	}else{
		Node *newHead=reverse(curr->next->next);
		curr=head;
		while(curr!=NULL){
			if(curr->data!=newHead->data){
				return false;
			}
			curr=curr->next;
			newHead=newHead->next;
		}
	}
	return true;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}