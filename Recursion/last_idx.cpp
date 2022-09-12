#include<iostream>
using namespace std;


int last_idx(int arr[],int size,int x){
	if(size==0){
		return -1;
	}

	if(arr[size-1]==x){
		return size-1;
	}

	return last_idx(arr,size-1,x);
}

int main(){

	int size;
	cin>>size;
	int x;cin>>x;
	int *arr =new int[size];

	for(int i=0;i<size;i++){
		cin>>arr[i];
	}

	cout<<last_idx(arr,size,x);
	delete [] arr;
}