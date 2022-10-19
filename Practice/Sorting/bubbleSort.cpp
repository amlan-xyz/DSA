#include<iostream>
using namespace std;

void bubbleSort(int arr[],int size){
	int j=0,i=0;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
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

	bubbleSort(arr,n);

	printArr(arr);
}