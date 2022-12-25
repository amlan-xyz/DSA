#include<bits/stdc++.h>
using namespace std;

#include "hashmap.h"

int main(){
	hash_map<int> mp;
	for(int i=0;i<10;i++){
		char c='0'+i;
		string key="abc";
		key+=c;
		int value=i+1;
		mp.insert(key,value);
		cout<<mp.getLoadFactor()<<endl;
	}

	mp.remove("abc2");
	mp.remove("abc7");

	for(int i=0;i<10;i++){
		char c='0'+i;
		string key="abc";
		key+=c;
		cout<<key<<":"<<mp.getValue(key)<<endl;
	}

	cout<<mp.getSize()<<endl;
}