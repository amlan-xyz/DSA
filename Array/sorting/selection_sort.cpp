#include<iostream>
using namespace std;


void select_sort(int arr[],int n){
	for(int i=0; i<n-1;i++){
		int min_value=arr[i];
		int min_idx=i;
		// loop to find min idx and min element
		for(int j=i+1;j<n;j++){
			if(arr[j]<min_value){
				min_value=arr[j];
				min_idx=j;
			}
		}

		// swap
		int temp=arr[i];
		arr[i]=arr[min_idx];
		arr[min_idx]=temp;
	}
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	select_sort(arr,n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" "; 
	}
}