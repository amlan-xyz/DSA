#include<iostream>
#include<math.h>
using namespace std;

int main(){
	long n;
	cin>>n;
	int decimal=0;
	int i=1;
	while(n){
		decimal+=(n%10)*(i);
		n/=10;
		i*=2;
	}
	cout<<decimal<<endl;
}