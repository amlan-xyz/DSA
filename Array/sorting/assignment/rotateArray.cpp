#include<iostream>
using namespace std;


void rotateArr(int arr[],int n,int d){
	
	// brute force
	// for(int i=0;i<d;i++){
	// 	int curr=arr[0];
	// 	for(int j=1;j<n;j++){
	// 		arr[j-1]=arr[j];
	// 	}
	// 	arr[n-1]=curr;
	// }

	int temp[d];
	for(int i=0;i<d;i++){
		temp[i]=arr[i];
	}

	for(int i=0;i<n-d;i++){
		arr[i]=arr[i+d];
	}

	for(int i=n-d,j=0;i<n,j<d;i++,j++){
		arr[i]=temp[j];
	}
}

int main(){

	int n,d;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cin>>d;
	rotateArr(arr,n,d);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" "; 
	}
}