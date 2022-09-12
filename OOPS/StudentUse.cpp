#include<iostream>
#include<string.h>
using namespace std;
#include "Student.cpp"

int main(){

	Student s1,s2,s3,s4;

    cout<<s1.roll<<" "<<s1.age<<endl;

    cout<<Student :: getTotalStudent()<<endl;
      Student s;
    s.roll = 101;
    cout << s.getRollNumber() << endl;
}

