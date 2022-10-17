template<typename T>

class StackUsingArray{
	T *data;
	int nextIdx;
	int capacity;

	public:

		StackUsingArray(){
			data=new T[4];
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

		void push(T element){
			if(nextIdx==capacity){
				T *newData=new T[2*capacity];
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

	T pop(){
		if(isEmpty()){
			cout<<"Stack is empty"<<endl;
			return 0;
		}
		nextIdx--;
		return data[nextIdx];
	}

	T top(){
		if(isEmpty()){
			cout<<"Stack is empty"<<endl;
			return 0;
		}
		return data[nextIdx-1];
	}

};



