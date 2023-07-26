/*
#include<iostream>
#include<vector>

using namespace std;

class BrowserHistory
{
private:
    vector<string> visitedPages;
    int accessPtr;
    int lastPagePtr;

public:
    BrowserHistory(string homepage)
    {
        visitedPages.push_back(homepage);
        accessPtr = 0;
        lastPagePtr = 0;
    }

    void visit(string url)
    {
        if (lastPagePtr < visitedPages.size() - 1)
        {
            visitedPages[lastPagePtr] = url;
            accessPtr = lastPagePtr;
        }
        else
            visitedPages.push_back()
    }

    string back(int steps)
    {
        
    }

    string forward(int steps)
    {
        ;
    }
};

void main()
{
    BrowserHistory bh = BrowserHistory("leetcode.com");
    bh.visit("google.com");
    bh.visit("facebook.com");
    bh.visit("youtube.com");
    bh.back(1);
    bh.back(1);
    bh.forward(1);
    bh.visit("linkedin.com");
    bh.forward(2);
    bh.back(2);
    bh.back(7);
}
*/