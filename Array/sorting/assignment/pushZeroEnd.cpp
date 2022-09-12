#include<iostream>
using namespace std;


void pushZero(int arr[],int n){
	int k=0;
	for(int i=0;i<n;i++){
		if(arr[i]!=0){
			int temp=arr[i];
			arr[i]=arr[k];
			arr[k]=temp;
			k++;
		}
	}
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	pushZero(arr,n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" "; 
	}
}