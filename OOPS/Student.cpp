// class Student{
// 	int age;


// 	public:
// 		char *name;
// 		Student(int age,char *name){
// 			this->age=age;

// 			// shallow copy
// 			// this->name=name;

// 			// deep copy
// 			this->name=new char[strlen(name)+1];
// 			strcpy(this->name,name);
// 		}


// 		// copy constructor

// 		Student(Student const &s){
// 			// shallow copy
// 			this->age=s.age;
// 			// this->name=s.name;
			

// 			// deep copy
// 			this->name=new char[strlen(s.name)+1];
// 			strcpy(this->name,s.name);
// 		}

// 		void display(){
// 			cout<<name<<" "<<age<<endl; 
// 		}
// };


// class Student{

// 	public:
// 		int age;
// 		int const roll;

// 		int &x; //age reference variable

// 		Student(int r,int age) : roll(r),age(age),x(this->age){
// 			// roll=r;
// 		}	

// };

class Student{

	private:
		static int totalStudents; // belongs to a class and no different copy is created
	
	public:
		int roll;
		int age;

		

		Student(){
			totalStudents++;
		}

		int getRoll(){
			return roll;
		}

		static int getRollNumber() {
        	return roll;
    	}

		static int getTotalStudent(){
			return totalStudents;
		}

};

int Student :: totalStudents=0; 