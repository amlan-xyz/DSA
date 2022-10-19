template <typename T>
class QueueUsingArray{
	T *data;
	int nextIdx;
	int firstIdx;
	int size;
	int capacity;
	public:
		QueueUsingArray(int s){
			data =new T[s];
			nextIdx=0;
			firstIdx=-1;
			size=0;
			capacity=s;
		}

		int getSize(){
			return size;
		}

		bool isEmpty(){
			return size==0;
		}

		void enqueue(T element){
			if(size==capacity){
				T *newData=new T[2*capacity];
				int j=0;
				for(int i=firstIdx;i<capacity;i++){
					newData[j]=data[i];
					j++;
				}

				for(int i=0;i<firstIdx;i++){
					newData[j]=data[i];
					j++;
				}
				delete [] data;
				data=newData;
				firstIdx=0; 
				nextIdx=capacity;
				capacity*2=capacity;
			}
			data[nextIdx]=element;
			nextIdx=(nextIdx+1)%capacity;
			if(firstIdx==-1){
				firstIdx=0;
			}
			size++;
		}

		T front(){
			if(isEmpty()){
				cout<<"Queue empty"<<endl;
				return 0;
			}

			return data[firstIdx];
		}

		T dequeue(){
			if(isEmpty()){
				cout<<"Queue empty"<<endl;
				return 0;
			}

			T ans=data[firstIdx];
			firstIdx=(firstIdx+1)%capacity;
			size--;
			if(size==0){
				firstIdx=-1;
				nextIdx=0;
			}
			return ans;
		}
};