#include<iostream>
using namespace std;

int subStr(string s,string output[]){
	if(s.empty()){
		output[0]="";
		return 1;
	}

	string smallString=s.substr(1);

	int smallOutputSize=subStr(smallString,output);

	for(int i=0;i<smallOutputSize;i++){
		output[i+smallOutputSize]=s[0]+output[i];
	}

	return 2*smallOutputSize;
}


int main(){

	string s;
	cin>>s;

	string * output=new string[1000];
	int count=subStr(s,output);

	for(int i=0;i<count;i++){
		cout<<output[i]<<endl;
	}
}