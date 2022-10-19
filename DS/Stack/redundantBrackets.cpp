#include <iostream>
#include <string>
using namespace std;
#include<stack>

bool checkRedundantBrackets(string s) {
	stack<char> st;
	bool isRedundant=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
			st.push(s[i]);
		}else if(s[i]=='('){
			st.push(s[i]);
		}else if(s[i]==')'){
			if(st.top()=='('){
				isRedundant=true;
			}
			while(st.top()=='+'|| st.top()=='-' || st.top()=='*' || st.top()=='/'){
				st.pop();
			}
			st.pop();
		}
	}
	return isRedundant;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}