#include<bits/stdc++.h>
#include "TrieNode.h"
class Trie{
	
	TrieNode *root;
	public:
	Trie(){
		root=new TrieNode('\0');
	}

	
	void insertWord(TrieNode *root,string word){
		// base case

		if(word.size()==0){
			root->isTerminal=true;
			return;
		}

		// small calculation
		TrieNode *child;
		int index=word[0]-'a';
		if(root->children[index]!=NULL){
			child=root->children[index];
		}else{
			child=new TrieNode(word[0]);
			root->children[index]=child;
		}

		// recursion
		insertWord(child,word.substr(1));
	}

	void insertWord(string word){
		insertWord(root,word);
	}

	
    bool search(TrieNode *parent, string word)
    {
        if (word.size() == 0)
            return parent->isTerminal;
        if (parent->children[word[0] - 'a'] != NULL)
            return search(parent->children[word[0] - 'a'], word.substr(1));
        else
            return false;
    }

    bool search(string word)
    {
        // Write your code here
        if (word.size() == 0)
            return false;
        return search(root, word);
    }


	void removeWord(TrieNode *root,string word){
		if(word.size()==0){
			root->isTerminal=false;
			return;
		}

		TrieNode *child;
		int index=word[0]-'a';
		if(root->children[index]!=NULL){
			child=root->children[index];
		}else{
			return ;
		}

		removeWord(child,word.substr(1));

		if(child->isTerminal==false){
			for(int i=0;i<26;i++){
				if(child->children[i]!=NULL){
					return;
				}
			}
			delete child;
			root->children[index]=NULL;
		}
	}

	void removeWord(string word){
		removeWord(root,word);
	}

	
bool patternMatching(vector<string> vect, string pattern) {
        // Write your code here
		for (int i = 0; i < vect.size(); i++)
        {
            while (vect[i] != "")
            {
                insertWord(vect[i]);
                vect[i] = vect[i].substr(1);
            }
        }
        return search(pattern);
    }

	// pallindrome pair
	  bool searchPalindrome(TrieNode *parent, string word)
    {
        if (parent->isTerminal || word.size() == 0)
            return true;
        if (parent->children[word[0] - 'a'] != NULL)
            return searchPalindrome(parent->children[word[0] - 'a'], word.substr(1));
        else
            return false;
    }

    bool searchPalindrome(vector<string> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            string s1 = v[i], s2 = v[i];
            reverse(s1.begin(), s1.end());
            if (searchPalindrome(root, s1))
                return true;
        }
        return false;
    }

    bool isPalindromePair(vector<string> words)
    {
        // Write your code here
        for (int i = 0; i < words.size(); i++)
            insertWord(words[i]);
        return searchPalindrome(words);
    }
};