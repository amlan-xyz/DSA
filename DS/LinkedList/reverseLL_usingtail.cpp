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

class Pair{
	public:

		Node * head;
		Node * tail;
};

using namespace std;



Pair reverseLLNew(Node *head){

	if(head==NULL || head->next==NULL){
		Pair ans;
		ans.head=head;
		ans.tail=head;
		return ans;
	}

	Pair smallAns=reverseLLNew(head->next);

	smallAns.tail->next=head;
	head->next=NULL;
	Pair ans;
	ans.head=smallAns.head;
	ans.tail=head;
	return ans;


}


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

Node * reverseLL(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}

	Node *smallAns=reverseLL(head->next);

	Node * temp=smallAns;
	while(temp->next!=NULL){
		temp=temp->next;
	}

	temp->next=head;
	head->next=NULL;
	return smallAns;
}

Node *reverseLL_Better(Node *head){
	return reverseLLNew(head).head;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLL_Better(head);
		print(head);
	}

	return 0;
}