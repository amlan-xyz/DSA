#include<iostream>
using namespace std;

int main() {
	// Write your code here
	long long n;
    cin>>n;
	int sum_of_even=0,sum_of_odd=0;
    while(n!=0){
		int temp=n%10;
		if(temp%2==0){
			sum_of_even+=temp;
		}else{
			sum_of_odd+=temp;
		}
        n/=10;
    }
	cout<<sum_of_even<<" "<<sum_of_odd;
}
