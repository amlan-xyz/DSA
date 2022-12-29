#include<bits/stdc++.h>
using namespace std;


#include "Trie.h"

int main(){
	Trie t;
	t.insertWord("ans");
	t.insertWord("are");
	cout<<t.search("ans")<<endl;
	t.removeWord("ans");
	cout<<t.search("ans")<<endl;
}