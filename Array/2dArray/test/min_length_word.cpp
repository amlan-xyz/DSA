#include<iostream>
#include<string.h>
using namespace std;


void minLengthWord(char input[],char output[]){

	int start=0;
	int end=0;
	int len=-1;
    for(len=0;input[len]!='0';len++);
	int minLength=len,minStartIdx=0;

	while(end<=len){

		if(end<len && input[end]!=' '){
			end++;
		}else{
			int curr_length=end-start;
			if(curr_length<minLength){
				minLength=curr_length;
				minStartIdx=start;
			}
			end++;
			start=end;
		}
	}

	for(int i=0;i<minLength;i++){
		output[i]=input[minStartIdx++];
	}
}

int main(){

	char input[1000],output[1000];

	cin.getline(input,1000);

	minLengthWord(input,output);

	cout<<output;
	
}