/*
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class WordDictionary
{
private:
	const int CHARS_COUNT = 'z' - 'a' + 1;
	int** adjacencyList;
	bool singleLetterExists;

public:

	WordDictionary()
	{
		adjacencyList = new int* [CHARS_COUNT] {nullptr};
		singleLetterExists = false;
	}

	void addWord(string word)
	{
		 Time complexity = O(word.size()) 

		if (word.size() == 1)
		{
			if (!adjacencyList[word[0] - 'a']) adjacencyList[word[0] - 'a'] = new int[CHARS_COUNT] {0};
			singleLetterExists = true;
		}

		for (int a = 0; a < word.size() - 1; ++a)
		{
			char* currentCh = &word[a];
			char* nextCh = &word[a + 1];

			if (!adjacencyList[*currentCh - 'a'])
				adjacencyList[*currentCh - 'a'] = new int[CHARS_COUNT] {0};
			adjacencyList[*currentCh - 'a'][*nextCh - 'a'] = 1;
		}
	}

	bool search(string word)
	{
		 Time complexity = O(word.size()) 

		if (word.size() == 0) return false;
		if (word.size() == 1)
		{
			if (word[0] == '.') return singleLetterExists;

			return adjacencyList[word[0] - 'a'] != nullptr;
		}

		bool lastLetterIndex = -1;
		for (int a = 0; a < word.size() - 1; ++a)
		{
			if (word[a] == '.') continue;

			if (adjacencyList[word[a] - 'a'])
			{
				if (word[a + 1] == '.') continue;

				if (!adjacencyList[word[a] - 'a'][word[a + 1] - 'a']) return false;

				lastLetterIndex = a;
			}
			else return false;
		}

		if (lastLetterIndex != word.size() - 2)
		{

		}

		return true;
	}
};

void main()
{
	WordDictionary dict;
	dict.addWord("");
}
*/