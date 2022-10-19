#include<iostream>
using namespace std;
#include "Queue.cpp"
using namespace std;


int main(){
	QueueUsingArray<int> q(10);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	cout<<q.front()<<endl;
	q.dequeue();
	cout<<q.front()<<endl;
	cout<<q.getSize()<<endl;
}