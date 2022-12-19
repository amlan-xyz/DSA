#include<bits/stdc++.h>



class PriorityQueue {
    // Declare the data members here
	private:
		vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
		pq.push_back(element);
		int childIndex=getSize()-1;
		while(childIndex>0){
			int parentIndex=(childIndex-1)/2;

			if(pq[childIndex]>pq[parentIndex]){
				int temp=pq[childIndex];
				pq[childIndex]=pq[parentIndex];
				pq[parentIndex]=temp;
			}else{
				break;
			}

			childIndex=parentIndex;
		}
    }

    int getMax() {
        // Implement the getMax() function here
		if(isEmpty()){
			return 0;
		}
		return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
		if(isEmpty()){
			return 0;
		}

		int ans=pq[0];
		pq[0]=pq[pq.size()-1];
		pq.pop_back();

		int parentIndex=0;
		int leftChildIndex=2*parentIndex+1;
		int rightChildIndex=2*parentIndex+2;


		while(leftChildIndex<pq.size()){
			int maxIndex=parentIndex;
			if(pq[maxIndex]<pq[leftChildIndex]){
				maxIndex=leftChildIndex;
			}

			if(rightChildIndex<pq.size() && pq[maxIndex]<pq[rightChildIndex]){
				maxIndex=rightChildIndex;
			}

			if(parentIndex==maxIndex){
				break;
			}
			int temp=pq[maxIndex];
			pq[maxIndex]=pq[parentIndex];
			pq[parentIndex]=temp;

			parentIndex=maxIndex;
			leftChildIndex=2*parentIndex+1;
			rightChildIndex=2*parentIndex+2;
		}

		return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
		return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
		if(pq.size()==0){
			return true;
		}
		return false;
	}
};