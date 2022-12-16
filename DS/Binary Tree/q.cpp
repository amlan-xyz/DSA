#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void retrivePasscodes(vector<string> strips){
	sort(strips.begin(),strips.end());
	for(int i=0;i<strips.size();i++){
		cout<<strips[i].substr(1,1);
	}
	for(int i=0;i<strips.size();i++){
		cout<<strips[i].substr(2,2);
	}
}

int main(){
	vector<string> strips;
	for(int i=0;i<5;i++){
		string s;
		cin>>s;
		strips.push_back(s);
	}

	retrivePasscodes(strips);
}