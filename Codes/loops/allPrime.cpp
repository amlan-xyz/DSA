#include <iostream>
using namespace std;

int main(){

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
  
    int n;
    cin>>n;

	for(int i=2;i<=n;i++){

		bool isDivided=false;
		int d=2;
		while(d<i){
			if(i%d==0){
				isDivided=true;
				break;
			}
			d++;
		}
		if(isDivided){
			continue;
		}else{
			cout<<i<<endl;
		}
	}
}
    

