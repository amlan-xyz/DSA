#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


int main(){

	unordered_map<string,int> our_map;
	// insert 
	pair<string,int> p("abc",1);
	our_map.insert(p);
	our_map["def"]=2;

	// find or access
	cout<<our_map["abc"]<<endl;
	cout<<our_map.at("abc")<<endl;
	// what if key is not present
	// cout<<our_map.at("ghi")<<endl;
	// but
	// cout<<our_map["ghi"]<<endl;
	// it will insert 0

	// check if key is present or not

	if(our_map.count("ghfi")>0){
		cout<<"It exist"<<endl;
	}else{
		cout<<"It doesnot exist"<<endl;
	}

}