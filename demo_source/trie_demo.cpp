//The MIT License (MIT)

//Copyright (c) 2019 OSS_G6. All rights reserved.

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

#include "trie.h"
#include <stdio.h>

int main (){

	Trie * root = new Trie();

	const char * words[5] = {"be", "bee", "can", "cat", "cd"};

	for(int i = 0; i < 5; ++i){
		printf("insert : %s\n", words[i]);
		root->insert(words[i]);
	}

	printf("\n");

	printf("%s : be\n", root->find("be") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : can\n", root->find("can") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : a\n", root->find("a") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : cat\n", root->find("cat") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : c\n", root->find("c") != 0 ? "Prefix Exist" : "Prefix Not Exist");

	printf("\n");

	printf("%s : c\n", root->string_exist("c") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : be\n", root->string_exist("be") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : bee\n", root->string_exist("bee") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : candy\n", root->string_exist("candy") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : cd\n", root->string_exist("cd") != 0 ? "String Exist" : "String Not Exist");

	delete root;

	return 0;
}
