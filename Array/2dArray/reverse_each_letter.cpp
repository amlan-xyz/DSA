#include<iostream>
#include<string.h>
using namespace std;

void reverseLetter(char input[]){

	int len;
	for(len=0;input[len]!='\0';len++);
	int start=0;
	for(int i=0;i<=len;i++){
		if(input[i]==' ' || input[i]=='\0'){
			int end=i-1;
			while(start<end){
				char temp=input[start];
				input[start]=input[end];
				input[end]=temp;
				start++;
				end--;
			}
			start=i+1;
		}
	}

}

int main(){
	int size=1e6;
	char input[size];
	cin.getline(input,size);

	reverseLetter(input);
	cout<<input;
}