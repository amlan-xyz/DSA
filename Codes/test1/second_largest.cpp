#include<iostream>
using namespace std;
#include <climits>

int main(){

	int n;
	cin>>n;
	int count=1;
	int largest=INT_MIN,second_largest=INT_MIN;
	while(count<=n){
		int a;
		cin>>a;
		if(a>largest){
			second_largest=largest;
			largest=a;
		}else if(a>second_largest && a!=largest){
			second_largest=a;
		}
		count++;
	}
	cout<<second_largest<<endl;
}

// #include<iostream>
// using namespace std;
// #include <climits>


// int main(){
//     int n;
//     cin>>n;
//     int max=INT_MIN,secondMax=INT_MIN;
//     int num;
//     int count=1;
    
//     while(count<=n){
//         cin>>num;
//         if (num>max){
//             secondMax=max;
//             max=num;
//         }
//         else if(num>secondMax&&num!=max){
//             secondMax=num;
//         }
//         count++;
        
        
//     }
//     cout<<secondMax<<endl;
    
// }
