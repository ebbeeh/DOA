#include "trie.h"


trie::trie()
{
	root = new trieNode;
}

trie::~trie()
{
	recursiveDeletion(root);
}

void trie::insert(const int* arr, int ID_LENGTH)
{
	// Root'en gemmes i current
	trieNode *current = root;

	// Da vi kender længden for alle ID, ved vi også hvor langt vi skal iterere.
	for (int i = 0; i < ID_LENGTH; i++)
	{			// bruger i til at indexe direkte med da der bruges int
		if (current->children_[arr[i]] == nullptr) {
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
		//is empty?
		if (current->children_[arr[i]] == nullptr)
			return false;

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
				return;
		}
		//delete begins here
		for (int i = 0; i < ID_LENGTH; i++)
		{
			temp = current;
			//check leafs
			if (current->children_[0] != nullptr || current->children_[1] != nullptr)
			{
				current->endOfID_ = false;
				return;
			}

			//remove begins
			if (current->parent_->parent_!= nullptr)	//checker om parent er root
			{
				if (current->parent_->children_[1] == nullptr || current->parent_->children_[0] == nullptr)
				{
					current = current->parent_;
					delete temp;
				}
				else //delete and return if parent has another child
				{
					//current = current->parent_;
					delete current;
					return;
				}
			}
		}
}



void trie::recursiveDeletion(trieNode * root)	//Inspirret ud fra Troels treap deletion
{

	if (root->children_[0] != nullptr)
	{
		recursiveDeletion(root->children_[0]);	//Recursiv venstre barn
	}
	if (root->children_[1] != nullptr)
	{
		recursiveDeletion(root->children_[1]); //Recursiv højre barn
	}
	if(root != nullptr)
		delete root;

}


