#include<bits/stdc++.h>
using namespace std;

int triplet_sum(int *arr,int n,int num){

	sort(arr,arr+n);

	int sum,count=0,xl=1,xr=1;

	for(int i=0;i<n-2;i++){
		int l=i+1;
		int r=n-1;

		while(l<r){
			sum=arr[i]+arr[l]+arr[r];
			if(sum<num){
				l++;
			}else if(sum>num){
				r--;
			}else{
				if(arr[i]==arr[r]){
					int total_element=r-i+1;
					count+=((total_element)*(total_element-1)*(total_element-2))/6;
					return count;
				}

				xl=1;
				xr=1;

				while(arr[l]==arr[l+1] && l<=r){
					xl++;
					l++;
				}

				while(arr[r]==arr[r-1] && l<=r){
					xr++;
					r--;
				}

				count+=xl*xr;
				l++;
				r--;
			}
		}

	}
	return count;
}

int main(){

	int n;
	cin>>n;

	int *arr=new int[n];


	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int sum;
	cin>>sum;
	cout<<triplet_sum(arr,n,sum);

}