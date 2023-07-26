
#include<bits/stdc++.h>

using namespace std;

int minDistance(string word1, string word2);
int getDistance(string& word1, string& word2, int i1, int i2, int** lookupTable);

int main()
{
	string word1 = "park";
	string word2 = "spake";
	cout << minDistance(word1, word2);

	getchar();
	return 0;
}

int minDistance(string word1, string word2) 
{
	int** lookupTable = new int*[word1.size()];
	for(int r = 0; r < word1.size(); ++r)
	{
		lookupTable[r] = new int[word2.size()];
		fill_n(lookupTable[r], word2.size(), -1);
	}

	int minEditDistance = getDistance(word1, word2, 0, 0, lookupTable);

	for(int r = 0; r < word1.size(); ++r)
	{
		delete[] lookupTable[r];
	}	
	delete[] lookupTable;

	return minEditDistance;
}

int getDistance(string& word1, string& word2, int i1, int i2, int** lookupTable)
{	
	if(i1 >= word1.size() && i2 >= word2.size())
		return 0;
	else if(i1 >= word1.size())
		return (word2.size()-i2);
	else if(i2 >= word2.size())
		return (word1.size()-i1);

	if(lookupTable[i1][i2] != -1)
		return lookupTable[i1][i2];

	if(word1[i1] == word2[i2])
		lookupTable[i1][i2] = getDistance(word1, word2, i1+1,i2+1,lookupTable);
	else
	{
		int deleteDist = 1 + getDistance(word1,word2,i1+1,i2,lookupTable); //The i1th character is deleted as it does not match i2th character
		int replaceDist = 1 + getDistance(word1, word2, i1+1,i2+1,lookupTable); //The i1th character is replaced with the i2th character
		int addDist = 1 + getDistance(word1, word2, i1,i2+1,lookupTable); //The it2th character is added before the i1th character in word1
		lookupTable[i1][i2] = min({deleteDist, replaceDist, addDist});
	}

	return lookupTable[i1][i2];	
}

