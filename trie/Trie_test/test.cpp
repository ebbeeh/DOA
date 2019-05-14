#include "pch.h"
#include "../trie/trie.cpp"

int arr[24] = { 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
int arr1[24] = { 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1 };
int arr2[24] = { 1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1 };
int arr3[24] = { 1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1 };
int arr4[24] = { 1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1 };
int arr5[24] = { 1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1 };
int arr6[10] = { 1,1,1,1,1,1,1,0,1,1};
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
	uut.insert(arr, 24, 125);
	uut.insert(arr1, 24, 126);
	uut.insert(arr2, 24, 123);
	uut.insert(arr3, 24, 122);
	uut.insert(arr4, 24, 121);
	uut.insert(arr5, 24, 127);
}

TEST_F(trieTest, Search_Non_Existing_ID_NOT_EQUAL)
{
	uut.insert(arr, 24, 121);

	ASSERT_NE(uut.search(arr1, 24), 121);
}

TEST_F(trieTest, Insert_2_different_ID_Search_EQUAL)
{
	uut.insert(arr, 24,130);
	uut.insert(arr1, 24,131);
	ASSERT_EQ(uut.search(arr, 24),130);

}

TEST_F(trieTest, Search_ID_WRONG_LENGHT_Return_NOT_EQUAL)
{
	uut.insert(arr, 24,110);
	
	ASSERT_NE(uut.search(arr, 200),110);

}

TEST_F(trieTest, remove_non_existent_ID_search_return_NOT_EQUAL)
{
	uut.remove(arr1, 24);
	ASSERT_NE(uut.search(arr1,24),131);
}

TEST_F(trieTest, remove_existent_ID_search_return_NOT_EQUAL)
{
	uut.insert(arr1, 24, 131);

	uut.remove(arr1, 24);
	ASSERT_NE(uut.search(arr1, 24),131);
}

TEST_F(trieTest, remove_ID_invalid_Length_search_return_EQUAL)
{
	uut.insert(arr1, 24,131);
	uut.remove(arr1, 23);
	ASSERT_EQ(uut.search(arr1, 24),131);
}

TEST_F(trieTest, remove_ID_arr2_search_for_arr1_search_return_EQUAL)
{
	uut.insert(arr1, 24,131);
	uut.insert(arr2, 23,132);
	uut.remove(arr2, 23);
	ASSERT_EQ(uut.search(arr1, 24),131);
}

TEST_F(trieTest, chaos_test_search_return_EQUAL)
{
	uut.insert(arr6, 10, 5);
	uut.insert(arr, 24, 125);
	uut.insert(arr1, 24, 126);
	uut.remove(arr2, 23);
	uut.insert(arr2, 24, 123);
	uut.remove(arr2, 24);
	uut.insert(arr3, 24, 122);
	uut.insert(arr4, 24, 121);
	uut.remove(arr2, 24);
	uut.insert(arr5, 24, 127);
	uut.remove(arr3, 24);
	uut.remove(arr, 24);
	uut.remove(arr1, 24);
	uut.remove(arr2, 24);
	uut.remove(arr3, 24);
	uut.remove(arr4, 24);
	uut.insert(arr5, 24, 127);
	

	ASSERT_EQ(uut.search(arr5, 10), 5);
}
