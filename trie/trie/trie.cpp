#include "trie.h"



trie::trie()
{
	root = new trieNode;
}

trie::~trie()
{
	delete root;
}

void trie::insert(int arr[])
{
	trieNode *current = root;
	
}

int * trie::search(int arr[])
{
	return nullptr;
}

void trie::remove(int arr[])
{
}
