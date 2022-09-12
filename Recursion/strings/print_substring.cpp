#include<iostream>
#include<string.h>
using namespace std;

void print_substring(string input,string output){
	if(input.length()==0){
		cout<<output<<endl;
		return ;
	}

	print_substring(input.substr(1),output);
	print_substring(input.substr(1),output+input[0]);
}

int main(){

	string input;
	cin>>input;
	string output="";
	print_substring(input,output);

}