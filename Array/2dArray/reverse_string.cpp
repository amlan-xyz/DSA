#include<iostream>
#include<string.h>
using namespace std;

void reverse_wordwise(char input[]){

	int n;
	for(n=0;input[n]!='\0';n++);

	int i=0,j=n-1;
	while(i<j){
		char temp=input[i];
		input[i]=input[j];
		input[j]=temp;
		i++;
		j--;
	}	
}


int main(){
	char input[100];
	cin.getline(input,6);

	reverse_wordwise(input);
	cout<<input;
}