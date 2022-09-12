#include<iostream>
#include<cmath>
using namespace std;

int main() {
	// Write your code here
	float basic_salary,total_salary;
    char grade;
    cin>>basic_salary;
    cin>>grade;
    if(grade=='A'){
        total_salary=basic_salary + .2*basic_salary + .5*basic_salary + 1700 - .11*basic_salary;
    }else if(grade=='B'){
        total_salary=basic_salary + .2*basic_salary + .5*basic_salary + 1500 - .11*basic_salary;
    }else{
        total_salary=basic_salary + .2*basic_salary + .5*basic_salary + 1300 - .11*basic_salary;
    }
    cout<<round(total_salary)<<endl;
}