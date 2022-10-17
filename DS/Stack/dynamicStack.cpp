

class StackUsingArray{
	int *data;
	int nextIdx;
	int capacity;

	public:

		StackUsingArray(){
			data=new int[4];
			nextIdx=0;
			capacity=4;
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
				int *newData=new int[2*capacity];
				for(int i=0;i<capacity;i++){
					newData[i]=data[i];
				}
				capacity*=2;
				delete [] data;
				data=newData;
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

