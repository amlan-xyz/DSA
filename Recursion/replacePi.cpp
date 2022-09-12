#include <iostream>
#include<string.h>
using namespace std;

void replace(char input[],int start){

	if(input[start]=='\0' || input[start+1]=='\0'){
		return ;
	}

	replace(input,start+1);

	if(input[start]=='p' && input[start+1]=='i'){
		int len;
        for(len=start;input[len]!='\0';len++);
		
		for (int i = len; i >= start + 2; i--) {
            input[i + 2] = input[i];
        }

		input[start]='3';
		input[start+1]='.';
		input[start+2]='1';
		input[start+3]='4';
	}

}

void replacePi(char input[]){

	replace(input,0);

}


int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}