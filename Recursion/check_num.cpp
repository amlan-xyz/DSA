#include<iostream>
using namespace std;


bool check_num(int *input,int n,int x){

	if(n==0){
		return false;
	}

	if(input[n-1]==x){
		return true;
	}

	return check_num(input,n-1,x);
}

int main(){

	int n;
	cin>>n;
	int *input=new int[n];

	for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

	int x;
	cin>>x;
    
    if(check_num(input,n,x)){
		cout<<"true";
	}else{
		cout<<"false";
	}

	delete [] input;
}