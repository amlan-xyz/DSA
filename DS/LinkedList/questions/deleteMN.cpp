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

Node* skipMdeleteN(Node *head,int m,int n){
	Node *curr=head,*temp;
	Node * toDelete;
	if(m==0){
		while(head!=NULL){
			toDelete=head;
			head=head->next;
			delete toDelete;
		}
	}else{
		while(curr){
			for(int countM=1;countM<m && curr!=NULL; countM++){
				curr=curr->next;
			}		

			if(curr==NULL){
				return head; 
			}

			temp=curr->next;
			for(int countN=1;countN<=n && temp!=NULL; countN++){
				toDelete=temp;
				temp=temp->next;
				delete toDelete;
			}

			curr->next=temp;

			curr=temp;

		}
	}


	return head;
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}