	
#include <iostream>
#include <string>
#include<stack>
using namespace std;    
	
	int countBracketReversals(string input) {
	// Write your code here
	stack <char> s;
    
    int totalreversal=0;
    for(int i=0;input[i]!='\0';i++)
    {  if(s.empty())
         s.push(input[i]);
     
     else
     {
        if(input[i]=='}' && s.top()=='{'  )   //{}
       		 {s.pop();}
       else if(input[i]=='{' && s.top()=='}')  //}{
       {
           s.pop();
           totalreversal+=2;
       }
        else								//{{   //}}
          s.push(input[i]);
     }  
        
    }
    
    if(s.size()%2==0)
        return s.size()/2+totalreversal;
    else return -1;
}




int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}