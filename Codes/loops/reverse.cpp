#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    cin>>n;
	int term = 0;
    while ( n> 0) {
        term = term * 10 + n % 10;
        n /= 10;
    }
	cout<<term;
}
