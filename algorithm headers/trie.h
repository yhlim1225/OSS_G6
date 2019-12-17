#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Node = 10;

int char_to_idx(char c){
	return c-'A';
}

class Trie{
	public:
		Trie *next[Node];
		bool is_terminal;
		Trie() : is_terminal(false){
			memset(next, 0, sizeof(next));
		}

		~Trie(){
			for(int i = 0 ; i < 10 ; ++i){
				if(next[i]) delete next[i];
			}
		}

	void insert(const char *key){
		if(*key == '\0') is_terminal = true;
		else{
			int idx = char_to_idx(*key);
			if(next[idx] == 0)
				next[idx] = new Trie();
			next[idx]->insert(key+1);
		}
	}

	Trie* find(const char *key){
		if(*key == 0) return this;
		int idx = char_to_idx(*key);
		if(next[idx] == 0) return NULL;
		return next[idx]->find(key+1);
	}

	bool string_exist(const char *key){
		if(*key == 0 && is_terminal)
			return true;
		int idx = char_to_idx(*key);
		if(next[idx] == 0) return false;
		return next[idx]->string_exist(key+1);
	}
};
#endif