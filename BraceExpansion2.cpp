
#include<bits/stdc++.h>

using namespace std;

vector<string> braceExpansionII(string expression);
set<string>* getSubset(string& expr, int* strPos);

int main()
{
    vector<string> strs = braceExpansionII("{{a,z},a{b,c},{ab,z}}");
    for(int i = 0; i < strs.size(); ++i)
    {
        cout << strs[i] << ", ";
    }

    getchar();
    return 0;
}

vector<string> braceExpansionII(string expression) 
{   
    int strPos = 0;
    set<string>* stringSet = getSubset(expression, &strPos);
    
    vector<string> res(stringSet->begin(), stringSet->end());

    return res;
}

set<string>* getSubset(string& expr, int* strPos)
{
    vector<set<string>*> subsets;
    set<string>* currSubset = new set<string>();
    set<string>* innerSubset;
    set<string>::iterator itr;
    string currSubstr = "";
    for(; *strPos < expr.size() && expr[*strPos] != '}'; ++(*strPos))
    {
        if(expr[*strPos] == ',')
        {
            if(currSubstr.size())
            {
                currSubset->insert(currSubstr);
                currSubstr.clear();
            }
        }
        else if(expr[*strPos] == '{')
        {
            if(currSubstr.size())
            {
                currSubset->insert(currSubstr);
                currSubstr.clear();
            }
            
            if(*strPos != 0 && expr[*strPos-1] == ',')
            {
                (*strPos)++;
                innerSubset = getSubset(expr, strPos);
                for(itr = innerSubset->begin(); itr != innerSubset->end(); ++itr)
                {
                    currSubset->insert(*itr);
                }
                delete innerSubset;
            }
            else
            {
                (*strPos)++;
                innerSubset = getSubset(expr, strPos);

                if(currSubset->size())
                    subsets.push_back(currSubset);
                if(innerSubset->size())
                    subsets.push_back(innerSubset);
                
                currSubset = new set<string>();;
            }
        }
        else
            currSubstr += expr[*strPos];
    }

    if(currSubstr.size())
    {
        currSubset->insert(currSubstr);
        subsets.push_back(currSubset);
    }
    else if(currSubset->size())
        subsets.push_back(currSubset);

    currSubset = subsets[0];
    set<string>* nextSubset = new set<string>();
    for(int i = 1; i < subsets.size(); ++i)
    {
        for(itr = currSubset->begin(); itr != currSubset->end(); ++itr)
        {
            for(set<string>::iterator itr2 = subsets[i]->begin(); itr2 != subsets[i]->end(); ++itr2)
            {
                nextSubset->insert(*itr + *itr2);
            }
        }
        delete currSubset;
        currSubset = nextSubset;
        nextSubset = new set<string>();
    }

    delete nextSubset;
    return currSubset;
}

/*
vector<set<string>> subsets;
    string currSubstr = "";
    set<string> currSubset;
    set<string>::iterator itr;
    for(; *strPos < expr.size() && expr[*strPos] != '}'; ++(*strPos))
    {
        if(expr[*strPos] == ',' && currSubstr.size())
        {
            currSubset.insert(currSubstr);
            currSubstr.clear();
        }
        else if(expr[*strPos] == '{')
        {   
            if(currSubstr.size())
            {
                currSubset.insert(currSubstr);
                currSubstr.clear();
            }
            
        
        }
        else
            currSubstr += expr[*strPos];
    }

    if(currSubstr.size() != 0)
    {
        currSubset.insert(currSubstr);
        subsets.push_back(currSubset);
    }

    currSubset.clear();
    for(itr = subsets[0].begin(); itr != subsets[0].end(); ++itr)
    {
        currSubset.insert(*itr);
    }
    for(int i = 1; i < subsets.size(); ++i)
    {
        for(itr = currSubset.begin(); itr != currSubset.end(); ++itr)
        {
            for(set<string>::iterator itr2 = subsets[i].begin(); itr2 != subsets[i].end(); ++itr2)
            {
                currSubset.insert(*itr + *itr2);
            }
        }
    }

    return currSubset;
*/