#pragma once
#define NEIGHBOURS 2	//Styre bredden af vores Trie
						// Hvor mange forskellige værdier der kan gemmes i trien
#include <iostream>
using namespace std;

class trie
{
private:
	class trieNode
	{
	public:
		trieNode(unsigned int value = NULL, trieNode *parent = nullptr, bool endOfID = false, int ApartmentNr = NULL)
			:value_(value), parent_(parent), endOfID_(endOfID), ApartmentNr_(ApartmentNr)
		{	}
		bool endOfID_;
		unsigned int value_;
		trieNode *children_[NEIGHBOURS] = { nullptr,nullptr };
		trieNode *parent_;
		int ApartmentNr_;
	private:
	};

	trieNode *root;
	void recursiveDeletion(trieNode *root);	//Til destructor til oprydning af hele trien
				// Se aflevering for uddybning af recursiv opskrift
public:
	trie();
	~trie();		//bruger RecursiveDeletion funktion til at sikre oprydning af alle noder
	void insert(const int *arr, int ID_LENGTH, int ApartmentNr);
	// Prækondition search(): der kan kun søges på ID'er med en længde på ID_LENGHT.'
	int search(const int *arr, int ID_LENGTH); 
	void remove(const int *arr, int ID_LENGTH);


};

