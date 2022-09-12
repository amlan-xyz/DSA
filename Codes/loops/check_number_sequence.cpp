#include<iostream>
using namespace std;


int main(){

	int n,count=1,prev,curr;
	cin>>n>>prev;
	bool isValid=true;
	bool isIncreasing=false;
	while(count<n){
		cin>>curr;
		int diff=curr-prev;
		if(diff==0){
			isValid=false;
		}else if(diff>0){
			isIncreasing=true;
		}else if(isIncreasing && diff<0){
			isValid=false;
		}
		prev=curr;
		count++;
	}
	cout<<isValid<<endl;
}