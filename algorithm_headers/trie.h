// The MIT License (MIT)

// Copyright (c) 2019 OSS_G6. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define Node 100

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
			for(int i = 0 ; i < Node ; ++i){
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
