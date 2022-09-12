#include<bits/stdc++.h>
using namespace std;

// aaabbbcc
// a3b3c2

string compressString(char input[]){
	int len;
	for(len=0;input[len]!='\0';len++);
	string ans="";
	for(int i=0;i<len;i++){
		int count=1;
		while(i<len-1 && input[i]==input[i+1]){
			count++;
			i++;
		}
		ans+=input[i];
		if(count>1){
			string ch= to_string(count);
			// cout<<ch;
			ans+=ch;
		}
	}

	return ans;

}

int main(){
	int size=1e6;
	char input[size];
	cin.getline(input,size);
	cout<<compressString(input);
	
}