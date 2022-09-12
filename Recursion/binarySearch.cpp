
#include <iostream>
using namespace std;

int search(int input[],int low,int high,int x){
    
    if(low>high){
        return -1;
    }
    
    int mid=(low+high)/2;
    
    if(input[mid]==x){
        return mid;
    }else if(input[mid]>x){
        return search(input,mid+1,high,x);
    }else{
        return search(input,low,mid-1,x);
    }
    
    
    
}

int binarySearch(int input[], int size, int x) {
    // Write your code here    
    return search(input,0,size-1,x);
}



int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}