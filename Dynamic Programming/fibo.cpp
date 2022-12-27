#include<bits/stdc++.h>
using namespace std;

// memoization

int fibo(int n,int *ans){
	if(n<=1){
		return n;
	}

	// check if output already exist
	if(ans[n]!=-1){
		return ans[n];
	}

	int a=fibo(n-1,ans);
	int b=fibo(n-2,ans);

	ans[n]=a+b;
	return ans[n];
}

// dynamic programming

int fibo_dp(int n){
	int *ans=new int[n+1];
	ans[0]=0;ans[1]=1;
	for(int i=2;i<=n;i++){
		ans[i]=ans[i-1]+ans[i-2];
	}

	return ans[n];
}

int main(){
	int n;
	cin>>n;
	int *ans=new int[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=-1;
	}
	cout<<"From memoization :"<<fibo(n,ans)<<endl;
	cout<<"From dynamic programming :"<<fibo_dp(n)<<endl;
	return 0;
}