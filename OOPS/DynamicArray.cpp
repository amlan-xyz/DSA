class DynamicArray{

	int *data;
	int nextIdx;
	int capacity; //total size;

	public:
		DynamicArray(){
			data=new int[5];
			nextIdx=0;
			capacity=5;
		}

		DynamicArray(DynamicArray const &d){
			this->data=new int[d.capacity];
			for(int i=0;i<d.nextIdx;i++){
				this->data[i]=d.data[i];
			}

			this->nextIdx=d.nextIdx;
			this->capacity=d.capacity;
		}

		void operator= (DynamicArray const &d){
			this->data=new int[d.capacity];
			for(int i=0;i<d.nextIdx;i++){
				this->data[i]=d.data[i];
			}

			this->nextIdx=d.nextIdx;
			this->capacity=d.capacity;
		}

		void add(int element){
			if(nextIdx==capacity){
				int *newData=new int[2*capacity];
				for(int i=0;i<capacity;i++){
					newData[i]=data[i];
				}
				delete [] data;
				data=newData;
				capacity*=capacity;
			}
			data[nextIdx]=element;
			nextIdx++;
		}

		int get(int i){

			if(i<nextIdx){
				return data[i];
			}
			return -1;
		}

		void add(int i,int element){
			if(i<nextIdx){
				data[i]=element;
			}else if(i==nextIdx){
				add(element);
			}else{
				return;
			}
		}

		void print(){
			for(int i=0;i<nextIdx;i++){
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}
};