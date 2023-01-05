#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n)
{

	//Write your code here
	if(m==0 && n==0){
		return input[0][0];
	}

	if(m<0 || n<0){
		return INT_MAX;
	}

	int x=minCostPath(input,m-1,n);
	int y=minCostPath(input,m-1,n-1);
	int z=minCostPath(input,m,n-1);
	int minCost=min(x,min(y,z));
	return minCost+input[m][n];
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}