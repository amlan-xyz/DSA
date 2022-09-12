#include<bits/stdc++.h>
using namespace std;


// 1
// 2 3
// 4 5 6

int main(){
	int n;
	cin>>n;
	int i=1,val=1;
	while(i<=n){
		int j=1;
		while(j<=i){
			cout<<val<<" ";
			j++;
			val++;
		}
		cout<<endl;
		i++;	
	}

//     1
//   2 3
// 4 5 6

	i=1;val=1;

	while(i<=n){
		int k=1;
		while(k<=n-i){
			cout<<"_";
			k++;
		}

		int j=1;
		while(j<=i){
			cout<<val<<" ";
			j++;
			val++;
		}
		cout<<endl;
		i++;	
	}

// 1
// 2 3
// 3 4 5	
// 4 5 6 7
// 5 6 7 8 9
// 6 7 8 9 10 11 
	
	i=1;
	while(i<=n){
		int j=1;
		val=i;
		while(j<=i){
			cout<<val<<" ";
			j++;
			val++;
		}
		cout<<endl;
		i++;	
	}


//     *
//   * * *
//	* * * * *   
	i=0;
    while(i<n){
        int k=1;
        while(k<=n-i-1){
            cout<<"_";
            k++;
        }
        int j=1;
        while(j<=2*i+1){
            cout<<"*";
            j++;
        }
        cout<<endl;i++;
    }

}



    