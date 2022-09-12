#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		
		// printing left	
		for(int j=1;j<=n-i+1;j++){
			cout<<j;
		}

		// printing *

		for(int star=1;star<i;star++){
			cout<<"**";
		}

		for(int k=n-i+1;k>=1;k--){
			cout<<k;
		}
		cout<<endl;
	}
}