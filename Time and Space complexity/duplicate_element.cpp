#include<iostream>
using namespace std;


int duplicateElement(int *arr,int n){

	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}

	return sum - (((n-2)*(n-1))/2);

}

int main(){

	int n;
	cin>>n;

	int *arr=new int[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<duplicateElement(arr,n);

	delete [] arr;
}