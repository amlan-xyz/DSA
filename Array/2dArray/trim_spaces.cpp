#include<iostream>
#include<string.h>
using namespace std;


void trim(char input[]){

	int len=strlen(input);

	for(int i=0;i<len;i++){

		if(input[i]==' '){
			for(int j=i;j<len;j++){
				input[j]=input[j+1];
			}
			i--;
		}
	}
}

int main(){
	int n;
	cin>>n;
	char input[n+1];
	cin.getline(input,n);

	trim(input);

	cout<<input<<endl;
	
}