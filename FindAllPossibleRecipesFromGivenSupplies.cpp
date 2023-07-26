
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    string val;
    vector<Node*> links;
    int satisfied;

    Node(string val)
    {
        this->val = val;
        satisfied = 0;
    }
};

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies);
forward_list<Node*>* getNodes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies);

int main()
{
    vector<string> recipes = {"bread","sandwich","burger"};
    vector<vector<string>> ing = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
    vector<string> spl = {"yeast","flour","meat"};

    vector<string> allRecipes = findAllRecipes(recipes, ing, spl);
    for(int i = 0; i < allRecipes.size(); ++i)
    {
        cout << allRecipes[i] << '\n';
    }

    getchar();
    return 0;
}

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
{
    forward_list<Node*>* nodeStack = getNodes(recipes, ingredients, supplies);

    unordered_map<string,bool> possibleRecipes;
    for(int i = 0; i < recipes.size(); ++i)
    {
        possibleRecipes.insert(pair<string,bool>(recipes[i], false));
    }
    for(int i = 0; i < supplies.size(); ++i)
    {
        unordered_map<string,bool>::iterator itr = possibleRecipes.find(supplies[i]);
        if(itr != possibleRecipes.end())
            itr->second = true;
    }

    Node* currNode = nullptr;
    while(!nodeStack->empty())
    {
        currNode = nodeStack->front();
        nodeStack->pop_front();

        for(int i = 0; i < currNode->links.size(); ++i)
        {
            currNode->links[i]->satisfied--;
            if(currNode->links[i]->satisfied == 0)
            {
                nodeStack->push_front(currNode->links[i]);
                possibleRecipes[currNode->links[i]->val] = true;
            }
        }
    }

    vector<string> allRecipes;
    for(int i = 0; i < recipes.size(); ++i)
    {
        if(possibleRecipes[recipes[i]])
            allRecipes.push_back(recipes[i]);
    }

    delete nodeStack;

    return allRecipes;
}

forward_list<Node*>* getNodes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
{
    unordered_map<string,Node*>* nodes = new unordered_map<string,Node*>();
    unordered_map<string,Node*>::iterator itr;
    for(int i = 0; i < recipes.size(); ++i)
    {
        itr = nodes->find(recipes[i]);
        if(itr == nodes->end())
        {
            nodes->insert(pair<string,Node*>(recipes[i], new Node(recipes[i])));
            itr = nodes->find(recipes[i]);
        }
        Node* recipeNode = itr->second;
        for(int j = 0; j < ingredients[i].size(); ++j)
        {
            itr = nodes->find(ingredients[i][j]);
            if(itr == nodes->end())
            {
                nodes->insert(pair<string,Node*>(ingredients[i][j], new Node(ingredients[i][j])));
                itr = nodes->find(ingredients[i][j]);
            }
            itr->second->links.push_back(recipeNode);
            recipeNode->satisfied++;
        }
    }

    forward_list<Node*>* nodesStack = new forward_list<Node*>();
    for(int i = 0; i < supplies.size(); ++i)
    {
        itr = nodes->find(supplies[i]);
        if(itr == nodes->end())
        {
            nodes->insert(pair<string,Node*>(supplies[i], new Node(supplies[i])));
            itr = nodes->find(supplies[i]);
        }
        nodesStack->push_front(nodes->find(supplies[i])->second);
    }
    delete nodes;

    return nodesStack;
}