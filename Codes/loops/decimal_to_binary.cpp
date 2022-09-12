#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	long binary=0;
	long i=1;
	while(n){
		binary+=(n%2)*i;
		n/=2;
		i*=10;
	}
	cout<<binary<<endl;
}