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


#ifndef _SKIP_LIST_H__
#define _SKIP_LIST_H__
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <exception>

template<typename KeyT, typename ValueT>
class SkipList {
	private:
		struct Node {
			KeyT	key;			// key
			ValueT	value;			// value
			Node ** forward;  		// pointers to different levels 
		};

		struct Node * m_header;		// the header node, empty
		int m_level;				// the max level of skip list

		static const int SL_MAX_LEVEL = 6;

		class NotFoundException: public std::exception {
			public:
				virtual const char * what() const throw() {
					return "cannot find the element in skiplist";
				}
		} excp_notfound;

	public:
		SkipList() {
			m_header = make_node(SL_MAX_LEVEL, 0, 0);
			m_level = 0;
		}

		~SkipList() {	

		}

	private:
		SkipList(const SkipList &);
		SkipList& operator=(const SkipList &);

	public:
		
		// search the given key from the skip list
		// if the key is not exist, throw exception
		
		inline ValueT operator[] (KeyT key) const {
			struct Node* x = m_header;

			// travels down until level-0
			for(int i = m_level; i >= 0; i--) {
				while(x->forward[i] != NULL && x->forward[i]->key < key) {
					x = x->forward[i];
				}
			}
			x = x->forward[0];
			if(x != NULL && x->key == key)
				return x->value;
			throw excp_notfound;
		}

		
		// insert a key->key pair into the list
		
		void insert(KeyT key, ValueT value) {
			struct Node * x = m_header;	
			struct Node * update[SL_MAX_LEVEL + 1];
			memset(update, 0, SL_MAX_LEVEL + 1);

			// travels down the list until we found a proper node
			for(int i = m_level; i >= 0; i--) {
				while(x->forward[i] != NULL && x->forward[i]->key < key) {
					x = x->forward[i];
				}
				update[i] = x; 
			}
			x = x->forward[0];

			// if it's not the largest key or duplicated key (middle ones)
			if(x == NULL || x->key != key) {        
				int lvl = random_level();	// random promotion

				// for nodes higher than  current max level
				// make 'header node' as it's prev
				if(lvl > m_level) {
					for(int i = m_level + 1; i <= lvl; i++) {
						update[i] = m_header;
					}
					m_level = lvl;
				}
				x = make_node(lvl, key, value);

				// for each node travlling down, relink into the skiplist
				for(int i = 0; i <= lvl; i++) {
					x->forward[i] = update[i]->forward[i];
					update[i]->forward[i] = x;
				}
			}
		}

		
		// delete a node by it's key
		
		void delete_key(KeyT key) {
			struct Node* x = m_header;	
			struct Node* update[SL_MAX_LEVEL + 1];
			memset(update, 0, SL_MAX_LEVEL + 1);

			// find the node, and record it's level update info
			for(int i = m_level; i >= 0; i--) {
				while(x->forward[i] != NULL && x->forward[i]->key < key) {
					x = x->forward[i];
				}
				update[i] = x; 
			}
			x = x->forward[0];

			// delete every level's key
			if(x != NULL && x->key == key) {
				for(int i = 0; i <= m_level; i++) {
					if(update[i]->forward[i] != x)
						break;
					update[i]->forward[i] = x->forward[i];
				}
				free(x);

				while(m_level > 0 && m_header->forward[m_level] == NULL) {
					m_level--;
				}
			}
		}

		void print() {
			for(int i=m_level-1;i>=0;i--) {
				Node* x = m_header->forward[i];
				printf("{");
				while(x != NULL) {
					printf("%d->%d", x->key, x->value);
					x = x->forward[i];
					if(x != NULL)
						printf(", ");
				}    
				printf("}\n");
			}
		}
	private:
		
		// normalize to [0.0 1.0]
		
		inline float rand_norm() { return (float) rand() / RAND_MAX; }

		
		// get the random promote level 
		
		int random_level() {
			int lvl = 0;
			// the possibility is 1/2 for each level	
			while(rand_norm() < 0.5f && lvl < SL_MAX_LEVEL)
				lvl++;

			return lvl;
		} 

		
		//make a node with specified level & key
		
		Node * make_node(int level, KeyT key, ValueT value) {
			Node * n = new Node;

			// the max forward entry for a key is : level + 1
			n->forward = new struct Node *[level + 1];
			n->key = key;
			n->value = value;

			return n;
		}
};

#endif
