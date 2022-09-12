#include <iostream>
using namespace std;


int str_to_int(char input[],int len){
	if(len==0){
		return input[len]-'0';
	}

	int smallAns=str_to_int(input,len-1);
	int a=input[len]-'0';
	return smallAns * 10 +a;
}

int stringToNumber(char input[]){
	int len;
	for(len=0;input[len]!='\0';len++);

	str_to_int(input,len-1);
}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
