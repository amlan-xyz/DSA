#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int budget[],int n){

		sort(budget,budget+n);

	int profit=-1;

	for(int i=0;i<n;i++){
		int m=n-i;

		int curr_profit=m*budget[i];
		if(curr_profit>profit){
			profit=curr_profit;
		}
	}

	return profit;

}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
