#include<bits/stdc++.h>
using namespace std;

int minCount(int n,int ans[]){
	if(sqrt(n)-floor(sqrt(n))==0){
		return 1;
	}

	if(n==0 || n==1 || n==2 || n==3){
		return n;
	}

	if(ans[n]!=-1){
		return ans[n];
	}

	int val=n;

	for(int i=1;(i*i)<=n;i++){
		val=min(val,1+minCount(n-(i*i),ans));
		ans[n]=val;
	}
	return ans[n];
}

int minCount(int n){
	int *ans=new int[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=-1;
	}
	return minCount(n,ans);
}

int dp(int n){
	vector<int> dp(n+1,INT_MAX);

	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for(int i=1;i<=n;i++){
		for(int j=1;j*j<=n;j++){
			int temp=j*j;
			if(i-temp>=0){
				dp[i]=min(dp[i],1+dp[i-temp]);
			}
		}
	}

	cout<<dp[n]<<endl;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}