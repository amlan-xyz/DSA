#include<iostream>
using namespace std;
template <typename T> 

class Node{

	public:
		T data;
		Node<T> *next;

		Node(T data){
			this->data=data;
			next=NULL;
		}
};

template <typename T> 
class Stack{
	Node<T> *head;
	int size; //no. of elements in stack
	public:
		Stack(){
			head=NULL;
			size=0;
		}

		int getSize(){
			return size;
		}

		bool isEmpty(){
			return head==NULL;
		}

	 	void push(T element){
			Node<T> *temp=new Node(element);
			temp->next=head;
			head=temp;
			size++;
		}	

		T pop(){
			if(isEmpty()){
				return -1;
			}

			Node<T> *temp=NULL;
			int num=head->data;
			temp=head->next;
			delete head;
			head=temp;
			size--;
			return num;
		}	

		T top(){
			if(isEmpty()){
				return -1;
			}
			return head->data;
		}
};