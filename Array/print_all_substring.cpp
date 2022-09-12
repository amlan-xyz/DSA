#include<bits/stdc++.h>
#include<string.h>
using namespace std;

void printSubstrings(char input[]){
	int n=strlen(input);
    
    for(int i=0;i<n;i++){
		string ans="";
        for(int j=i;j<n;j++){
            ans+=input[j];
            cout<<ans<<endl;
        }
    }
}

int main(){
	int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}