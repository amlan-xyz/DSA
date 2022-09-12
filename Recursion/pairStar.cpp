#include <iostream>
using namespace std;




void replace(char input[],int start){
    
    if(input[start]=='\0'){
        return ;
    }
    
    replace(input,start+1);
    
    if(input[start]==input[start+1]){
        int len;
        for(len=start;input[len]!='\0';len++);
        
        for(int i = len;i>=start +1;i--){
			input[i+1] = input[i];
		}
        
        input[start+1]='*';
    }
}

void pairStar(char input[]) {
    // Write your code here
    
    replace(input,0);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
