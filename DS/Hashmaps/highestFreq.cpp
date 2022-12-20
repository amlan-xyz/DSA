#include<bits/stdc++.h>
using namespace std;

int highestFrequency(int *arr,int n){
	unordered_map<int,int> mp;

	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}

	int maxFreq=0;
	int currMaxFreq=0;

	for(int i=0;i<n;i++){
		if(mp[arr[i]]>currMaxFreq){
				maxFreq=arr[i];
				currMaxFreq=mp[arr[i]];
		}
	}

	return maxFreq;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}