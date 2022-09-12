#include<iostream>
using namespace std;


void merge_array(int arr1[],int n,int arr2[],int m,int ans[],int x){
	int i=0,j=0,k=0;
	while(i<n && j<m){

		if(arr1[i]<arr2[j]){
			ans[k]=arr1[i];
			i++;
		}else{
			ans[k]=arr2[j];
			j++;
		}
		k++;
	}

	if(i<n){
		for(;k<x,i<n;k++,i++){
			ans[k]=arr1[i];
		}
	}else{
		for(;k<x,j<m;k++,j++){
			ans[k]=arr2[j];
		}
	}
	
}

int main(){

	int n,m;
	cin>>n>>m;
	int arr1[n],arr2[m];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}

	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	int x=n+m;
	int ans[x];
	merge_array(arr1,n,arr2,m,ans,x);

	for(int i=0;i<n+m;i++){
		cout<<ans[i]<<" "; 
	}
}