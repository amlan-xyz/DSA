#include<iostream>
using namespace std;


void selectionSort(int arr[]){

	// find min idx and min value 
	// then swap it
	// initailly the min value is arr[0] and minidx is also 0
	for(int i=0;i<5;i++){

		// loop to find the min value
		int minVal=arr[i];
		int minIdx=i;
		for(int j=i+1;j<5;j++){
			if(arr[j]<minVal){
				minVal=arr[j];
				minIdx=j;
			}
		}

		int temp=arr[i];
		arr[i]=arr[minIdx];
		arr[minIdx]=temp;
	}
}

void printArr(int arr[]){
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
}



int main(){
	int arr[5]={5,4,3,2,1};

	selectionSort(arr);

	printArr(arr);
}