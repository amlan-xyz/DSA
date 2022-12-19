#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
	for(int i=0;i<n;i++){
		int leftChildIdx=2*i+1;
		int rigthChildIdx=2*i+2;
		if(leftChildIdx<n && rigthChildIdx<n){
			if(!(arr[leftChildIdx]<arr[i] && arr[rigthChildIdx]<arr[i])){
				return false;
			}
		}else if(leftChildIdx<n && !(arr[leftChildIdx]<arr[i])){
			return false;
		}

		
	}
	return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}