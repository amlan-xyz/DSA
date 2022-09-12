#include<iostream>
#include<string.h>
using namespace std;

bool isPermutation(char input1[],char input2[]){

	int size1=strlen(input1);
	int size2=strlen(input2);
	int freq[26]={0};
	int temp=0;

	for(int i=0;i<size1;i++){
		temp=input1[i]-97;
		freq[temp]++;
	}

	for(int i=0;i<size2;i++){
		temp=input2[i]-97;
		freq[temp]--;
	}

	for(int i=0;i<26;i++){
		if(freq[i]!=0){
			return false;
		}
	}

	return true;
}

int main(){
	char input1[100];
	char input2[100];
	cin>>input1>>input2;

	cout<<(isPermutation(input1,input2) ? "true":"false");

	
}