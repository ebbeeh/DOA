#include "trie.h"


trie::trie()
{
	root = new trieNode;
}

trie::~trie()
{
	delete root;
}

void trie::insert(const int* arr, int ID_LENGTH)
{
	// Root'en gemmes i current
	trieNode *current = root;

	// Da vi kender længden for alle ID, ved vi også hvor langt vi skal iterere.
	for (int i = 0; i < ID_LENGTH; i++)
	{			// bruger i til at indexe direkte med da der bruges int
		if (arr[i] != current->children_[arr[i]]->value_)
		{
			if (i == ID_LENGTH - 1)
			{
				current->children_[arr[i]] = new trieNode(arr[i], current, true);
				return;
			}
			else
				current->children_[arr[i]] = new trieNode(arr[i], current);
		}
		current = current->children_[arr[i]];
	}
}

bool trie::search(const int * arr, int ID_LENGTH)
{
	// Root'en gemmes i current
	trieNode *current = root;

	for (int i = 0; i < ID_LENGTH; i++)
	{
		// Early exit
		if (arr[i] != current->children_[arr[i]]->value_)
		{
			return false; 
		}
		else if (ID_LENGTH - 1 == i && current->children_[arr[i]]->endOfID_ == true)
		{
			return true;
		}
		current = current->children_[arr[i]];
	}
	// Hvis vi går ud af for-løkken, er det fordi ID'en ikke findes
	return false;
}

void trie::remove(const int *arr, int ID_LENGTH)
{
	// Root'en gemmes i current
	trieNode *current = root;
	trieNode *temp = nullptr;

	//Er der overhovedet noget i trien?
	for (int i = 0; i < 2; i++)
	{
		if (current->children_[i] != nullptr)
			break;
		else
			return;
	}
	/*
	//hvis ja, fortsættes der her.
	for (int i = 0; i < ID_LENGTH - 1; i++)
	{
		if (arr[i] == current->children_[0]->value_)
		{
			current = current->children_[0];
			if (current->endOfID_ == true)
				break;
		}
		else if (arr[i] == current->children_[1]->value_)
		{
			current = current->children_[1];
			if (current->endOfID_ == true)
				break;
		}
	}
	*/

	if (search(arr,ID_LENGTH))
	{

		//delete begins here
		for (int i = 0; i < ID_LENGTH - 1; i++)
		{
			temp = current;
			if (current->parent_->value_ != NULL)
			{
				current = current->parent_;
				delete temp;
			}
			else
				return;
		}
	}
}
