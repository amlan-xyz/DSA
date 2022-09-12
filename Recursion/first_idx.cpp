#include<iostream>
using namespace std;


int first_idx(int arr[],int size,int x){
	if(size==0){
		return -1;
	}

	if(arr[0]==x){
		return 0;
	}

	int ans=first_idx(arr+1,size-1,x);

	if(ans==-1){
		return -1;
	}else{
		ans+=1;
	}

	return ans;
}

int main(){

	int size;
	cin>>size;
	int x;cin>>x;
	int *arr =new int[size];

	for(int i=0;i<size;i++){
		cin>>arr[i];
	}

	cout<<first_idx(arr,size,x);
	delete [] arr;
}