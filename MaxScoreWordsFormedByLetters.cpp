/*
#include<iostream>
#include<vector>

using namespace std;

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score);
void getMaxScore(int word, vector<string>& words, vector<int> lettersLeft, int currentScore, int* maxScore,
	vector<int>& wordScores);

void main()
{
	string wordVals[4] = { "dog","cat","dad","good" };
	char letterVals[9] = { 'a','a','c','d','d','d','g','o','o' };
	int scoreVals[26] = { 1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0 };

	vector<string> words(wordVals, wordVals + 4);
	vector<char> letters(letterVals, letterVals + 9);
	vector<int> scores(scoreVals, scoreVals + 26);

	cout << maxScoreWords(words, letters, scores);
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
{
	vector<int> lettersCount(26, 0);
	for (int a = 0; a < letters.size(); ++a)
	{
		lettersCount[letters[a] - 'a']++;
	}

	vector<int> wordScores;
	for (int a = 0; a < words.size(); ++a)
	{
		int wordScore = 0;
		for (int b = 0; b < words[a].size(); ++b)
		{
			wordScore += score[words[a][b] - 'a'];
		}
		wordScores.push_back(wordScore);
	}
	
	int maxScore = 0;
	for (int a = 0; a < words.size(); ++a)
	{
		getMaxScore(a, words, lettersCount, 0, &maxScore, wordScores);
	}

	return maxScore;
}

void getMaxScore(int word, vector<string>& words, vector<int> lettersLeft, int currentScore, int* maxScore,
	vector<int>& wordScores)
{
	if (word == words.size()) return;

	for (int a = 0; a < words[word].size(); ++a)
	{
		if (lettersLeft[words[word][a] - 'a']-- == 0) return;
	}

	currentScore += wordScores[word];
	*maxScore = max(*maxScore, currentScore);

	for (int a = word + 1; a < words.size(); ++a)
	{
		getMaxScore(a, words, lettersLeft, currentScore, maxScore, wordScores);
	}
}

class BitMaskSol
{
private :
	void calculateWordScores(vector<string>& words, int* wordScores, vector<int>& letterScores)
	{
		for (int a = 0; a < words.size(); ++a)
		{
			int wordScore = 0;
			for (char ch : words[a])
			{
				wordScore += letterScores[ch - 'a'];
			}
			wordScores[a] = wordScore;
		}
	}

	void getLetterCount(int* letterCounts, vector<char>& letters)
	{
		for (char ch : letters)
		{
			letterCounts[ch - 'a']++;
		}
	}

	bool checkLettersLeft(vector<int> lettersLeft, string& word)
	{
		for (int a = 0; a < word.size(); ++a)
		{
			if (lettersLeft[word[a] - 'a']-- == 0) return false;
		}

		return true;
	}

	void updateLettersCount(vector<int>& lettersLeft, string& word)
	{
		for (int a = 0; a < word.size(); ++a)
		{
			lettersLeft[word[a] - 'a']--;
		}
	}

public :
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
	{
		int* wordScores = new int[words.size()];
		calculateWordScores(words, wordScores, score);

		int letterCounts[26] = { 0 };
		getLetterCount(letterCounts, letters);

		int maxScore = 0;
		for (int n = 1; n < pow(2, words.size()); ++n)
		{
			int setScore = 0;
			vector<int> lettersLeft(letterCounts, letterCounts + 26);
			for (int i = 0; i <= words.size(); ++i)
			{
				if ((n & (1 << i)) != 0)
				{
					if (checkLettersLeft(lettersLeft, words[words.size() - 1 - i]))
					{
						setScore += wordScores[words.size() - 1 - i];
						updateLettersCount(lettersLeft, words[words.size() - 1 - i]);
					}
					else
					{
						setScore = 0;
						break;
					}
				}
			}

			maxScore = setScore > maxScore ? setScore : maxScore;
		}

		delete[] wordScores;

		return maxScore;
	}
};
*/