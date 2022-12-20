#include<bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here
	unordered_map<int,int> mp;
	int count=0;
	for(int i=0;i<n;i++){
		if(mp.count(arr[i])==0){
			mp[arr[i]]=1;
		}else{
			mp[arr[i]]+=1;
		}

		if(mp.count(-arr[i])){
			count+=mp[-arr[i]];
			if(arr[i]==0){
				count--;
			}
		}
	}
	return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}