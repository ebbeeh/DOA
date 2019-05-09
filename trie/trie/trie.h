#pragma once
#define NEIGHBOURS 2
#include <iostream>
using namespace std;

class trie
{
public:
	trie();
	~trie();
	void insert(int arr[]);
	int* search(int arr[]);
	void remove(int arr[]);

private:
	class trieNode
	{
	public:
		trieNode(unsigned int value = NULL, trieNode *parent = nullptr, int* data = nullptr)
			:value_(value), parent_(parent), dataPointer_(data)
		{	}
		int *dataPointer_;
		unsigned int value_;
		trieNode *children_[NEIGHBOURS] = {};
		trieNode *parent_;
	};

	trieNode *root;
};

