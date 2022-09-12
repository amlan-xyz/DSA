#include<iostream>
using namespace std;

int second_largest(int arr[],int n){
	int lar=INT_MIN;
    int sec_lar=INT_MIN;
    
    for(int i=0;i<n;i++){
		if(arr[i]>lar){
			sec_lar=lar;
			lar=arr[i];
		}else{
			if(arr[i]>sec_lar && arr[i]!=lar){
				sec_lar=arr[i];
			}
		}
		cout<<lar<<" "<<sec_lar<<endl;
    }
    return sec_lar;
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<second_largest(arr,n);

}