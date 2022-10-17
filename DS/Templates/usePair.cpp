#include<iostream>
using namespace std;

#include "Pair.cpp"

int main(){

	Pair<int,double> p1;
	p1.setX(10);
	p1.setY(20.2);
	cout<<p1.getX()<<" "<<p1.getY()<<endl;

	Pair<Pair<int,char>, int > p2;

	p2.setY(10);

	Pair<int,char> p3;
	p3.setX(20);
	p3.setY('j');

	p2.setX(p3);
	cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;
}