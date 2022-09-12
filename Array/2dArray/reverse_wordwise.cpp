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
	int start=0;
	for(int i=0;i<=n;i++){
		if(input[i]==' ' || input[i]=='\0'){
			int end=i-1;
			while(start<end){
				char temp=input[start];
				input[start]=input[end];
				input[end]=temp;
				start++;end--;
			}
			start=i+1;
		}
	}


}


int main(){
	char input[1000];
	cin.getline(input,1000);

	reverse_wordwise(input);
	cout<<input;
}