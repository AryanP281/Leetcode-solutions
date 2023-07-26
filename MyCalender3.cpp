
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;


class MyCalendarThree 
{
private :
    map<int,int> intervalCounts; 

public:
    MyCalendarThree() 
    {
       
    }
    
    int book(int start, int end) 
    {
        intervalCounts[start]++;
        intervalCounts[end]--;

        int maxOverlaps = 0;
        int currOverlaps = 0;
        for(map<int,int>::iterator itr = intervalCounts.begin(); itr != intervalCounts.end(); ++itr)
        {
            currOverlaps += itr->second;

            maxOverlaps = max(maxOverlaps, currOverlaps);
        }

        return currOverlaps;
    }
};

int main()
{
    vector<vector<int>> bookings = {{24,40},{43,50},{27,43},{5,21},{30,40},{14,29},{3,19},{3,14},{25,39},{6,19}};

    MyCalendarThree* obj = new MyCalendarThree();
    for(int a = 0; a < bookings.size(); ++a)
    {
        cout << obj->book(bookings[a][0], bookings[a][1]) << ' ';
    }

    delete obj;
    getchar();
    return 0;
}

struct IntervalNode
{
    Vec interval;
    Vec heights;
    int maxEnd;
    IntervalNode* left;
    IntervalNode* right;


    IntervalNode(int start, int end, int maxEnd)
    {
        this->interval = Vec(start,end);
        this->maxEnd = maxEnd;

        this->heights = Vec(0,0);
        this->left = nullptr;
        this->right = nullptr;
    }
};

class IntervalTree
{
private :
    IntervalNode* root;

    IntervalNode* insertNode(IntervalNode* currNode, IntervalNode* newNode)
    {
        if(!currNode)
            return newNode;

        if(newNode->interval.first <= currNode->interval.first)
            currNode->left = insertNode(currNode->left, newNode);
        else
            currNode->right = insertNode(currNode->right, newNode);

        currNode->heights.first = currNode->left ? max(currNode->left->heights.first+1,currNode->left->heights.second+1) : 0;
        currNode->heights.second = currNode->right ? max(currNode->right->heights.first+1, currNode->right->heights.second+1) : 0;

        int balanceFactor = currNode->heights.first - currNode->heights.second;
        if(balanceFactor < -1)
        {
            if(newNode->interval.first <= currNode->right->interval.first)
               currNode->right = rightRotate(currNode->right);
        
            currNode = leftRotate(currNode);
        }
        else if(balanceFactor > 1)
        {
            if(newNode->interval.first > currNode->left->interval.first)
                currNode->left = leftRotate(currNode->left);
            currNode = rightRotate(currNode);
        }
        else
            currNode->maxEnd = max(currNode->maxEnd, max(currNode->left ? currNode->left->maxEnd : 0, currNode->right ? currNode->right->maxEnd : 0));

        return currNode;
    }

    IntervalNode* rightRotate(IntervalNode* node)
    {
        IntervalNode* leftChild = node->left;

        IntervalNode* temp = leftChild->right;
        leftChild->right = node;
        node->left = temp;

        if(temp)
            node->heights.first = max(temp->heights.first+1, temp->heights.second+1);
        else
            node->heights.first = 0;

        leftChild->heights.second = max(node->heights.first+1, node->heights.second+1);

        node->maxEnd = max(node->interval.second, max(node->left ? node->left->maxEnd : 0, node->right ? node->right->maxEnd : 0));
        leftChild->maxEnd = max(leftChild->maxEnd, max(leftChild->left ? leftChild->left->maxEnd : 0, leftChild->right ? leftChild->right->maxEnd : 0));

        return leftChild;
    }

    IntervalNode* leftRotate(IntervalNode* node)
    {
        IntervalNode* rightChild = node->right;

        IntervalNode* temp = rightChild->left;
        rightChild->left = node;
        node->right = temp;

        if(temp)
            node->heights.second = max(temp->heights.first+1, temp->heights.second+1);
        else
            node->heights.second = 0;

        rightChild->heights.first = max(node->heights.first+1, node->heights.second+1);

        node->maxEnd = max(node->interval.second, max(node->left ? node->left->maxEnd : 0, node->right ? node->right->maxEnd : 0));
        rightChild->maxEnd = max(rightChild->maxEnd, max(rightChild->left ? rightChild->left->maxEnd : 0, rightChild->right ? rightChild->right->maxEnd : 0));

        return rightChild;
    }

    int getOverlapCount(IntervalNode* currNode, Vec& query)
    {
        if(!currNode)
            return 0;

        auto intervalsOverlap = [](Vec& i1, Vec& i2) -> bool {
            return ((i1.first <= i2.first && i1.second > i2.first) || (i2.first < i1.first && i2.second > i1.first));
        };
        
        int overlaps = 1*(intervalsOverlap(currNode->interval, query));
        if(currNode->left && currNode->left->maxEnd > query.first)
            overlaps += getOverlapCount(currNode->left, query);
        
        overlaps += getOverlapCount(currNode->right, query);

        return overlaps;
    }

    void deleteSubtree(IntervalNode* currNode)
    {
        if(!currNode)
            return;

        deleteSubtree(currNode->left);
        deleteSubtree(currNode->right);

        delete currNode;
    }

public :
    IntervalTree()
    {
        this->root = nullptr;
    }

    ~IntervalTree()
    {
        deleteSubtree(this->root);
    }

    void insertInterval(int start, int end)
    {
        IntervalNode* newInterval = new IntervalNode(start, end, end);

        this->root = insertNode(root, newInterval);
    }

    int getOverlaps(int start, int end)
    {
        Vec query(start, end);

        return getOverlapCount(root, query);
    }
};
