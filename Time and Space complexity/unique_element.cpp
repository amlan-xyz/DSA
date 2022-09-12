#include<iostream>
using namespace std;

int uniqueElement(int *arr, int n){

	int ans=0;
	for(int i=0;i<n;i++){
		ans^=arr[i];
	}

	return ans;
}

int main(){

	int n;
	cin>>n;

	int *arr=new int[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<uniqueElement(arr,n);

	delete [] arr;
}