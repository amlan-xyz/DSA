#include <iostream>
using namespace std;

void mergeArray(int input[],int l,int mid,int r){

	int l_size=mid-l+1;
	int left[l_size+1];
	int r_size=r-mid;
	int right[r_size+1];

	for(int i=0;i<l_size;i++){
		left[i]=input[i+l];
	}

	for(int i=0;i<r_size;i++){
		right[i]=input[i+mid+1];
	}

	left[l_size]=right[r_size]=INT_MAX;

	int l_start=0,r_start=0;

	for(int i=l;i<=r;i++){
		if(left[l_start]<=right[r_start]){
			input[i]=left[l_start];
			l_start++;
		}else{
			input[i]=right[r_start];
			r_start++;
		}
	}
}


void merge_sort(int input[],int l,int r){

	if(l==r){
		return ;
	}

	int mid=(l+r)/2;

	merge_sort(input,l,mid);
	merge_sort(input,mid+1,r);

	mergeArray(input,l,mid,r);

}

void mergeSort(int input[],int size){

	if(size==0){
		return;
	}

	merge_sort(input,0,size-1);
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }

  delete [] input;
}