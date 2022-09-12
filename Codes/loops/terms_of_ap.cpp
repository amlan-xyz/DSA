#include<iostream>
using namespace std;

int main(){

	int x;
	cin>>x;
	int count=1;
	for(int i=1;  count<=x;i++){
		int temp=(3*i)+2;
		if(temp%4!=0){
			cout<<temp<<" ";
			count++;
		}
	}
}