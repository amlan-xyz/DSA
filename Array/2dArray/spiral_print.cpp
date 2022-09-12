#include<iostream>
using namespace std;


void spiralPrint(int input[][100],int row,int col){
	
	int row_start=0,row_end=row;
	int col_start=0,col_end=col;
	while(row_start<row && col_start<col){

		for(int i=col_start;i<col_end;i++){
			cout<<input[row_start][i]<<" ";
		}
		row_start+=1;
		for(int i=row_start;i<row_end;i++){
			cout<<input[i][col_end-1]<<" ";
		}
		col_end-=1;

		// IF CONDITION OR IT WILL PRINT 
        if(row_start<row_end){
		for(int i=col_end-1;i>=col_start;i--){
			cout<<input[row_end-1][i]<<" ";
		}
		row_end-=1;
        }
        if(col_start<col_end){
		for(int i=row_end-1;i>=row_start;i--){
			cout<<input[i][col_start]<<" ";
		}
		col_start+=1;
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
	spiralPrint(arr,row,col);
}