#include <iostream>
#include <string>
using namespace std;
#include<unordered_map>

string uniqueChar(string str) {
	// Write your code here
	unordered_map<char,int> mp;
	string ans="";
	for(int i=0;i<str.length();i++){
		if(mp[str[i]]>0){
			continue;
		}
		mp[str[i]]++;
		ans+=str[i];
	}
	return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}