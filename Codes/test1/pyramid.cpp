//    1
//   212
//  32123
// 4321234

#include<iostream>
using namespace std;


int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){

		// print spaces
		for(int spaces=1;spaces<=n-i;spaces++){
			cout<<" ";
		}

		// printing
		int val=i;
		for(int j=1;j<=i;j++){
			cout<<val;
			val--;
		}

		// other side
		for(int temp=2;temp<=i;temp++){
			cout<<temp;
		}
	cout<<endl;
	}

}