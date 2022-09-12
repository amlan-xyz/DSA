#include<iostream>
using namespace std;

void printArray(int input[][100],int row,int col){

	for(int i=0;i<row;i++){
		for(int j=row-i;j>0;j--){
			for(int k=0;k<col;k++){
				cout<<input[i][k]<<" ";
			}
			cout<<endl;
		}		
	}
	
}

int main(){
	int arr[100][100];
	int row,col;
	cin>>row>>col;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
	printArray(arr,row,col);
}