

class StackUsingArray{
	int *data;
	int nextIdx;
	int capacity;

	public:

		StackUsingArray(int totalSize){
			data=new int[totalSize];
			nextIdx=0;
			capacity=totalSize;
		}

		// return the number of elements present in my stack

		int size(){
			return nextIdx;
		}

		bool isEmpty(){
			// if(nextIdx==0){
			// 	return true;
			// }else{
			// 	return false;
			// }
			return nextIdx==0;
		}

		// insert element;

		void push(int element){
			if(nextIdx==capacity){
				cout<<"Stack full"<<endl;
				return;
			}
			data[nextIdx]=element;
			nextIdx++;
		}

	// delete element

	int pop(){
		if(isEmpty()){
			cout<<"Stack is empty"<<endl;
			return -1;
		}
		nextIdx--;
		return data[nextIdx];
	}

	int top(){
		if(isEmpty()){
			cout<<"Stack is empty"<<endl;
			return -1;
		}
		return data[nextIdx-1];
	}

};

