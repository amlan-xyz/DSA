#include<iostream>
using namespace std;

void insertionSort(int arr[],int size){
	int key,j;

	for(int i=1;i<size;i++){
		key=arr[i];
		j=i;
		while(arr[j-1]>key && j>0){
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=key;
	}
}

void printArr(int arr[]){
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
}



int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	insertionSort(arr,n);

	printArr(arr);
}