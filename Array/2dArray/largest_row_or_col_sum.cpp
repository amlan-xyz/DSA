#include<iostream>
using namespace std;


int main(){

	int row,col;
	cin>>row>>col;
	int max_row_sum=INT_MIN;
	int max_col_sum=INT_MIN;
	int sum;
	int arr[row][col];
	int max_row;
	for(int i=0;i<row;i++){

		sum=0;
		for(int j=0;j<col;j++){
			cin>>arr[i][j];
			sum+=arr[i][j];
		}
		if(sum>max_row_sum){
			max_row=i;
			max_row_sum=max(max_row_sum,sum);
		}
	}

	int max_col;
	for(int i=0;i<col;i++){
		sum=0;
		for(int j=0;j<row;j++){
			sum+=arr[j][i];
		}
		if(sum>max_col_sum){
			max_col=i;
			max_col_sum=max(max_col_sum,sum);
		}
	}

	if(row==0 && col==0){
		cout<<"row "<<0<<" "<<INT_MIN;
	}else{
		if(max_row_sum<max_col_sum){
			cout<<"column "<<max_col<<" "<<max_col_sum<<endl;
		}else{
			cout<<"row "<<max_row<<" "<<max_row_sum<<endl;
		}
	}
	


}