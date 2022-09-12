#include<iostream>
using namespace std;


int main(){

	int n;
	cin>>n;
	int count=1;
	int ans=0;
	while(count*count<=n){
		ans=count;
		count++;
	}
	cout<<ans<<endl;
}