#include<iostream>
using namespace std;


void sort_arr(int input[],int n){

	int new_zero=0,new_two=n-1;
	int i=0;
	while(i<=new_two){
		for(int j=0;j<n;j++){
		cout<<input[j];
		}
		cout<<endl;
		if(input[i]==0 && new_zero==i){
			i++;new_zero++;
		}else if(input[i]==0){
			int temp=input[i];
			input[i]=input[new_zero];
			input[new_zero]=temp;
			i++;new_zero++;
		}else if(input[i]==2){
			int temp=input[i];
			input[i]=input[new_two];
			input[new_two]=temp;
			new_two--;
		}else{
			i++;
		}
	}
	
}

int main(){

	int n;
	cin>>n;
	int input[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
	}

	sort_arr(input,n);

	for(int i=0;i<n;i++){
		cout<<input[i];
	}
}