#include<iostream>
using namespace std;

void inplaceHeapSort(int pq[],int n){
	// build heap
	for(int i=1;i<n;i++){
		int childIndex=i;
			while(childIndex>0){
				int parentIndex=(childIndex-1)/2;

				if(pq[childIndex]<pq[parentIndex]){
					int temp=pq[childIndex];
					pq[childIndex]=pq[parentIndex];
					pq[parentIndex]=temp;
				}else{
					break;
				}
				childIndex=parentIndex;
			}
	}

	int size=n;
	while(size>1){
		// remove element
	
		int temp=pq[0];
		pq[0]=pq[size-1];
		pq[size-1]=temp;
		size--;
		int parentIndex=0;
		int leftChildIndex=2*parentIndex+1;
		int rightChildIndex=2*parentIndex+2;

		// if leftchildidx is out of bound so is righchild 
		// so we can check for only left child

		while(leftChildIndex<size){
			int minIndex=parentIndex;
			if(pq[minIndex]>pq[leftChildIndex]){
				minIndex=leftChildIndex;
			}

			if(rightChildIndex<size && pq[minIndex]>pq[rightChildIndex]){
				minIndex=rightChildIndex;
			}

			if(parentIndex==minIndex){
				break;
			}

			int temp=pq[minIndex];
			pq[minIndex]=pq[parentIndex];
			pq[parentIndex]=temp;

			parentIndex=minIndex;
			leftChildIndex=2*parentIndex+1;
			rightChildIndex=2*parentIndex+2;
		}
	}
	

}


int main(){
	int input[]={5,1,2,0,8};
	inplaceHeapSort(input,5);
	for(int i=0;i<5;i++){
		cout<<input[i]<<" ";
	}
	return 0;
}