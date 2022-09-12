#include<iostream>
using namespace std;



int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int m;
	cin>>m;

	for(int i=0;i<m;i++){
		cin>>arr[i];
	}

	cout<<second_largest(arr,n);

}