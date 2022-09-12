#include<bits/stdc++.h>
using namespace std;

char rep(string s) {
            
        char minChar;
		bool b=false;
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
					minChar=s[j];
					b=true;
					break;
                }
            } 
			if(b){
				break;
			}           
        }    
		return minChar;    
}


	int main(){

		string s;
		cin>>s;

		cout<<rep(s);
	}