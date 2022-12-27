#include<bits/stdc++.h>
using namespace std;

// brute force

int sol_recursion(int n){
	if(n<=1){
		return 0;
	}

	// recursive call
	int y=INT_MAX,z=INT_MAX;

	int x=sol_recursion(n-1);
	if(n%2==0){
		y=sol_recursion(n/2);
	}
	if(n%3==0){
		z=sol_recursion(n/3);
	}
	return min(min(x,y),z)+1;
}

// memoization

int helper_memoization(int n,int ans[]){
	if(n<=1){
		return 0;
	}

	if(ans[n]!=-1){
		return ans[n];
	}

	int x=helper_memoization(n-1,ans);
	int y=INT_MAX,z=INT_MAX;
	if(n%2==0){
		y=helper_memoization(n/2,ans);
	}
	if(n%3==0){
		z=helper_memoization(n/3,ans);
	}

	ans[n]=min(min(x,y),z)+1;
	return ans[n];
}

int sol_memoization(int n){
	int *ans=new int[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=-1;
	}

	return helper_memoization(n,ans);
}

// dp

int sol_dp(int n){
	int *ans=new int[n+1];
	ans[0]=0;
	ans[1]=0;
	for(int i=2;i<=n;i++){
		int a=INT_MAX,b=INT_MAX,c=INT_MAX;

		a=ans[i-1];
		if(i%2==0){
			b=ans[i/2];
		}
		if(i%3==0){
			c=ans[i/3];
		}

		ans[i]=min(min(a,b),c)+1;
	}

	return ans[n];
}

int main(){
	int n;
	cin>>n;
	cout<<sol_recursion(n)<<endl;
	cout<<sol_memoization(n)<<endl;
}