#include "pch.h"
#include "../trie/trie.cpp"

int arr[24] = { 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
int arr1[24] = { 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1 };
class trieTest : public testing::Test
{
protected:
	void SetUp()
	{

	}
	void TearDown()
	{

	}

	trie uut;
	
};

TEST_F(trieTest, InsertNormalID_NoError) 
{
	uut.insert(arr, 24);

	cout << uut.search(arr, 24) << endl;
	
}

TEST_F(trieTest, Search_Non_Existing_ID_Search_False)
{
	uut.insert(arr, 24);

	ASSERT_FALSE(uut.search(arr1, 24));

}

TEST_F(trieTest, Insert_2_different_ID_Search_True)
{
	uut.insert(arr, 24);
	uut.insert(arr1, 24);
	ASSERT_TRUE(uut.search(arr, 24));

}
TEST_F(trieTest, Search_ID_WRONG_LENGHT_Return_FALSE)
{
	uut.insert(arr, 24);
	
	ASSERT_FALSE(uut.search(arr, 200));

}

TEST_F(trieTest, remove_non_existent_ID_search_return_false)
{
	uut.remove(arr1, 24);
	ASSERT_FALSE(uut.search(arr1,24));
}

TEST_F(trieTest, remove_existent_ID_search_return_false)
{
	uut.insert(arr1, 24);

	uut.remove(arr1, 24);
	ASSERT_FALSE(uut.search(arr1, 24));
}

TEST_F(trieTest, remove_ID_invalid_Length_search_return_false)
{
	uut.insert(arr1, 24);
	uut.remove(arr1, 23);
	ASSERT_TRUE(uut.search(arr1, 24));
}