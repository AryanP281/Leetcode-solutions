
#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();

    return 0;
}

vector<int> minOperations(string boxes) 
{
    int* rightBoxCount = new int[boxes.size()]();
    rightBoxCount[boxes.size()-1] = 1*(boxes[boxes.size()-1] == '1');
    for(int r = boxes.size()-2; r >= 0; --r)
    {
        rightBoxCount[r] = rightBoxCount[r+1] + 1*(boxes[r] == '1');
    }

    int* leftBoxCount = new int[boxes.size()]();
    leftBoxCount[0] = 1*(boxes[0] == '1');
    for(int l = 1; l < boxes.size(); ++l)
    {
        leftBoxCount[l] = leftBoxCount[l-1] + 1*(boxes[l] == '1');
    }

    int* rightOps = new int[boxes.size()]();
    for(int r = boxes.size()-2; r >= 0; --r)
    {
        rightOps[r] = rightOps[r+1] + rightBoxCount[r+1];
    }

    int* leftOps = new int[boxes.size()]();
    for(int l = 1; l < boxes.size(); ++l)
    {
        leftOps[l] = leftOps[l-1] + leftBoxCount[l-1];
    }

    vector<int> result;
    for(int i = 0; i < boxes.size(); ++i)
    {
        result.push_back(leftOps[i] + rightOps[i]);
    }

    delete[] rightBoxCount;
    delete[] leftBoxCount;
    delete[] rightOps;
    delete[] leftOps;

    return result;
}