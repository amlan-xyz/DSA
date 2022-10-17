#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> st;
	int arr[5]={1,2,3,4,5};

	for(int i=0;i<5;i++){
		st.push(arr[i]);
	}

	cout<<st.size()<<" "<<st.empty()<<endl;
	for(int i=0;i<5;i++){
		cout<<st.top()<<endl;
		st.pop();
	}	
	cout<<st.size()<<" "<<st.empty()<<endl;
}