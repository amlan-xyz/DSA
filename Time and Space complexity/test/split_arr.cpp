#include<bits/stdc++.h>
using namespace std;

bool helper(int *input,int n,int start,int l_sum,int r_sum){

	if(start==n){
		if(l_sum==r_sum){
			return true;
		}else{
			return false;
		}
	}

	if(input[start]%5==0){
		l_sum+=input[start];
	}else if(input[start]%3==0){
		r_sum+=input[start];
	}else{
		return helper(input,n,start+1,l_sum+input[start],r_sum) || helper(input,n,start+1,l_sum,r_sum+input[start]);
	}

	return helper(input,n,start+1,l_sum,r_sum);
}

bool splitArray(int *input,int n){

	return helper(input,n,0,0,0);
}

int main(){

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;
}