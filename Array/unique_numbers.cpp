#include<iostream>
using namespace std;


int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++){
			bool isNotUnique=false;
			for(int j=0;j<n;j++){
				// if(i==j){
				// 	continue;
				// }else{
					if(arr[i]==arr[j] && i!=j){
						isNotUnique=true;
					}
				// }
			}
			if(isNotUnique==false){
				cout<<arr[i]<<endl;
				break;
			}
			
		}
	}

	
}