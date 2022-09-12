#include<bits/stdc++.h>
using namespace std;

int pair_sum(int *arr,int n,int num){
	int l=0,r=n-1,xl=1,xr=1,count=0,sum;
	sort(arr,arr+n);
	while(l<r){

		sum=arr[l]+arr[r];
		if(sum<num){
			l++;
		}else if(sum>num){
			r--;
		}else{

			if(arr[l]==arr[r]){
				int n_count=r-l+1;
				count+=((n_count)*(n_count-1))/2;
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
	cout<<pair_sum(arr,n,sum);


}