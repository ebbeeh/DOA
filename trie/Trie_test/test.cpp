#include "pch.h"
#include "../trie/trie.h"

int ID[24] = { 1 };

TEST(trie, InsertNormalID_NoError) 
{
	trie testObj;

	testObj.insert(ID,24);
}


