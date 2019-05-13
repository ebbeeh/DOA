#pragma once
#define NEIGHBOURS 2
#define MAX_ID_LENGTH 24
#include <iostream>
using namespace std;

class trie
{
public:
	trie();
	~trie();
	void insert(const int *arr, int ID_LENGTH);
	// Prækondition search(): der kan kun søges på ID'er med en længde på ID_LENGHT.'
	bool search(const int *arr, int ID_LENGTH); 
	void remove(const int *arr, int ID_LENGTH);

private:
	class trieNode
	{
	public:
		trieNode(unsigned int value = NULL, trieNode *parent = nullptr, bool endOfID = false)
			:value_(value), parent_(parent), endOfID_(endOfID)
		{	}
		bool endOfID_;
		unsigned int value_;
		trieNode *children_[NEIGHBOURS] = {nullptr};
		trieNode *parent_;
	};

	trieNode *root;
};

