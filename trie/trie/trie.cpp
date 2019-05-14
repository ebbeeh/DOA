#include "trie.h"


trie::trie()
{
	root = new trieNode;
}

trie::~trie()
{
	recursiveDeletion(root);
}

void trie::insert(const int* arr, int ID_LENGTH,int ApartmentNr)
{
	// Root'en gemmes i current
	trieNode *current = root;

	// Da vi kender længden for alle ID, ved vi også hvor langt vi skal iterere.
	for (int i = 0; i < ID_LENGTH; i++)
	{			// bruger i til at indexe direkte med da der bruges int
		if (current->children_[arr[i]] == nullptr) {
				if (i == ID_LENGTH - 1)
				{
					current->children_[arr[i]] = new trieNode(arr[i], current, true, ApartmentNr);
					return;
				}
				else
					current->children_[arr[i]] = new trieNode(arr[i], current);
		}
		current = current->children_[arr[i]];
	}
}

int trie::search(const int * arr, int ID_LENGTH)
{
	// Root'en gemmes i current

	trieNode *current = root;


	for (int i = 0; i < ID_LENGTH; i++)
	{
		//is empty?
		if (current->children_[arr[i]] == nullptr)
			return NULL;

		// Early exit
		if (arr[i] != current->children_[arr[i]]->value_)
		{
			return NULL; 
		}
		else if (ID_LENGTH - 1 == i && current->children_[arr[i]]->endOfID_ == true)
		{
			return current->children_[arr[i]]->ApartmentNr_;
		}
		current = current->children_[arr[i]];
	}
	// Hvis vi går ud af for-løkken, er det fordi ID'en ikke findes
	return NULL;
}

void trie::remove(const int *arr, int ID_LENGTH)
{
	trieNode *current = root;
	trieNode *temp = nullptr;

	for (int i = 0; i < ID_LENGTH; i++)
	{
		if (current->children_[arr[i]] != nullptr)
		{
			if (arr[i] == current->children_[arr[i]]->value_)
			{
				current = current->children_[arr[i]];
				if (current->endOfID_ == true && ID_LENGTH - 1 == i)
					break;
			}
		}
		else
		{
			return;
		}
	}

	// Vi står nu i bunden af den ID der ønskes slettet. Medmindre dette ID ikke findes

	//Hvis vores ID/Ord har et child skal vi ikke slette den
	if (current->children_[0] != nullptr || current->children_[1] != nullptr)
	{
		current->endOfID_ = false;		
		return;
	}
	while (current != root)
	{
		temp = current;
		current = current->parent_;
		current->children_[temp->value_] = nullptr;	//Ændrer child pointer til en nullptr, for den node der skal slettes
		delete temp;

		if (current->children_[0] != nullptr || current->children_[1] != nullptr) //Hvis den node vi er kommet til har et andet barn stopper vi
			return;
		if (current->endOfID_)		//Hvis den node vi er kommet til afslutter et andet ord/id stopper vi
			return;
		
	}
}



void trie::recursiveDeletion(trieNode * root)	//Inspirret ud fra Troels treap deletion
{
	//RC
	if (root->children_[0] != nullptr)
	{
		recursiveDeletion(root->children_[0]);	//Recursiv 'venstre' barn
	}
	if (root->children_[1] != nullptr)
	{
		recursiveDeletion(root->children_[1]); //Recursiv 'højre' barn
	}

	//BC
	if (root != nullptr)	//lidt ekstra sikkerhed selvom det bliver tjekket i RC
		delete root;

}


