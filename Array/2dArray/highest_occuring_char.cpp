#include<iostream>
#include<string.h>
using namespace std;

char highestOccuringChar(char input[]){
	int freq[26]={0};

	int len=strlen(input);
	for(int i=0;i<len;i++){
		int temp=input[i]-97;
		freq[temp]++;
	}	

	int maxOccur=-1;
	int maxOccurIdx;
	for(int i=0;i<26;i++){
		if(freq[i]>maxOccur){
			maxOccur=freq[i];
			maxOccurIdx=i;
		}
	}
	char ans=maxOccurIdx+97;
	return ans;
}

int main(){
	int size=1e6;
	char input[size];
	cin.getline(input,size);
	cout<<highestOccuringChar(input);
	
}