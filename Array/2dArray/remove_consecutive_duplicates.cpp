#include<iostream>
#include<string.h>
using namespace std;

void removeDuplicates(char input[]){

	int len;
	for(int len=0;input[len]!='\0';len++);

	for(int i=1;input[i]!='\0';i++){
		if(input[i]==input[i-1]){
			int j;
			for( j=i;input[j]!='\0';j++){
				input[j]=input[j+1];
		
			}
			i--;
		}
	}
}

int main(){
	char input[100];
	cin>>input;


	removeDuplicates(input);
	cout<<input;	
}