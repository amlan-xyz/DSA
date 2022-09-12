#include<iostream>
using namespace std;

void Leaders(int arr[],int len){

	for(int i=0;i<len;i++){
        bool isLeader=true;
        for(int j=i+1;j<len;j++){
            if(arr[i]<arr[j]){
                isLeader=false;
            }
        }
        if(isLeader){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){


	int arr[100];
	int len;
	cin>>len;

	for(int i=0;i<len;i++){
		cin>>arr[i];
	}

	Leaders(arr,len);
}