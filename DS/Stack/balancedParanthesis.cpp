#include<iostream>
#include<stack>
using namespace std;


bool isBalanced(string expression) 
{
	stack<char> st;
	for(int i=0;i<expression.length();i++){
		if(st.empty() && expression[i]==')'){
			return false;
		}else if(st.empty()){
			st.push(expression[i]);
		}else if(expression[i]=='('){
			st.push(expression[i]);
		}else if(expression[i]==')' && st.top()=='('){
			st.pop();
		}else{
			st.push(expression[i]);
		}

	}
		if(st.empty()){
			return true;
		}else{
			return false;
		}
	
	
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}