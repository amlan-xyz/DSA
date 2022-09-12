#include<iostream>
#include<string.h>
using namespace std;

void removeOccurence(char input[],char c){

	int len=strlen(input);
	for(int i=0;input[i]!='\0';i++){
		if(input[i]==c){
			for(int j=i;j<len;j++){
				input[j]=input[j+1];
			}
			i--;
		}
	}
}

int main(){
	int size=1e6;
	char input[size];
	cin.getline(input,size);
	char c;
	cin>>c;
	removeOccurence(input,c);
	cout<<input;
}