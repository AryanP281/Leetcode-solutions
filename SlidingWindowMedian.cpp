
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

struct Node
{
    int val;
    Vec heights;
    Vec sizes;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        this->heights = Vec(0,0);
        this->sizes = Vec(0,0);
        this->left = nullptr;
        this->right = nullptr;
    }

};
 
class AvlTree
{
private :
    Node* root;

    Node* addNode(Node* currNode, Node* newNode)
    {
        if(!currNode)
            return newNode;

        if(newNode->val <= currNode->val)
        {
            currNode->left = addNode(currNode->left, newNode);
            currNode->sizes.first++;
        }
        else
        {
            currNode->right = addNode(currNode->right, newNode);
            currNode->sizes.second++;
        }

        currNode->heights.first = currNode->left ? max(currNode->left->heights.first+1, currNode->left->heights.second+1) : 0;
        currNode->heights.second = currNode->right ? max(currNode->right->heights.first+1, currNode->right->heights.second+1) : 0;
        
        int balanceFactor = currNode->heights.first - currNode->heights.second; 
        if(balanceFactor < -1)
        {
            //New node added to right subtree

            if(newNode->val <= currNode->right->val)
            {
                //Right Left Case
                currNode->right = rightRotate(currNode->right);
                currNode = leftRotate(currNode);
            }
            else
            {
                //Right Right Case
                currNode = leftRotate(currNode);
            }
            
        }
        else if(balanceFactor > 1)
        {
            //New node add left subtree

            if(newNode->val <= currNode->left->val)
            {
                //Left Left Case
                currNode = rightRotate(currNode);
            }
            else
            {
                //Left Right Case
                currNode->left = leftRotate(currNode->left);
                currNode = rightRotate(currNode);
            }
        }

        return currNode;
    }

    Node* removeNode(Node* currNode, int val)
    {    
        if(currNode->val == val)
        {
            //No Child
            if(!currNode->left && !currNode->right)
            {
                delete currNode;
                return nullptr;
            }
            //Both Children
            if(currNode->left && currNode->right)
            {
                Node* inorderPredecessor = getInorderPredecessor(currNode);
                currNode->val = inorderPredecessor->val;

                //Deleting the inorder predecessor
                currNode->left = removeNode(currNode->left, inorderPredecessor->val);
                currNode->sizes.first--;
            }
            else
            {
                //One Child
                if(currNode->left)
                {
                    Node* temp = currNode->left;
                    delete currNode;
                    return temp;
                }
                else
                {
                    Node* temp = currNode->right;
                    delete currNode;
                    return temp;
                }
            }

        }
        else if(val < currNode->val)
        {
            currNode->left = removeNode(currNode->left,val);
            currNode->sizes.first--;
        }
        else if(val > currNode->val)
        {
            currNode->right = removeNode(currNode->right, val);
            currNode->sizes.second--;
        }

        currNode->heights.first = currNode->left ? max(currNode->left->heights.first+1,currNode->left->heights.second+1) : 0;
        currNode->heights.second = currNode->right ? max(currNode->right->heights.first+1,currNode->right->heights.second+1) : 0;

        int balanceFactor = currNode->heights.first - currNode->heights.second;
        if(balanceFactor < -1)
        {
            //Y is Right Child

            if(currNode->right->heights.first > currNode->right->heights.second)
            {
                //Right Left Case
                currNode->right = rightRotate(currNode->right);
                currNode = leftRotate(currNode);
            }
            else
            {
                //Right Right Case
                currNode = leftRotate(currNode);
            }
        }
        else if(balanceFactor > 1)
        {
            //Y is Left Child

            if(currNode->left->heights.first > currNode->left->heights.second)
            {
                //Left Left Case
                currNode = rightRotate(currNode);
            }
            else
            {
                //Left Right Case
                currNode->left = leftRotate(currNode->left);
                currNode = rightRotate(currNode);
            }
        }

        return currNode;
    }

    Node* leftRotate(Node* node)
    {
        Node* rightChild = node->right;

        Node* temp = rightChild->left;
        rightChild->left = node;
        node->right = temp;

        if(temp)
        {
            node->heights.second = max(temp->heights.first+1, temp->heights.second+1);
            node->sizes.second = temp->sizes.first + temp->sizes.second + 1;
        }
        else
        {
            node->heights.second = 0;
            node->sizes.second = 0;
        }

        rightChild->sizes.first = node->sizes.first + node->sizes.second + 1;
        rightChild->heights.first = max(node->heights.first+1, node->heights.second+1);

        return rightChild;
    }

    Node* rightRotate(Node* node)
    {
        Node* leftChild = node->left;

        Node* temp = leftChild->right;
        leftChild->right = node;
        node->left = temp;

        if(temp)
        {
            node->sizes.first = temp->sizes.first + temp->sizes.second + 1;
            node->heights.first = max(temp->heights.first+1, temp->heights.second+1);
        }
        else
        {
            node->sizes.first = 0;
            node->heights.first = 0;
        }

        leftChild->heights.second = max(node->heights.first+1, node->heights.second+1);
        leftChild->sizes.second = node->sizes.first + node->sizes.second + 1;

        return leftChild;
    }

    Node* getInorderPredecessor(Node* currNode)
    {
        Node* node = currNode->left;

        while(node->right)
        {
            node = node->right;
        }

        return node;
    }

public :
    AvlTree()
    {
        root = nullptr;
    }

    ~AvlTree()
    {
        list<Node*> stack;
        stack.push_back(this->root);

        Node* currNode;
        while(stack.back())
        {
            currNode = stack.back();
            stack.pop_back();
            if(currNode->left)
                stack.push_back(currNode->left);
            if(currNode->right)
                stack.push_back(currNode->right);
            
            delete currNode;
        }
    }

    void insertVal(int val)
    {
        Node* newNode = new Node(val);

        if(!root)
        {
            root = newNode;
            return;
        }

        this->root = addNode(this->root, newNode);
    }

    void removeVal(int val)
    {
        this->root = removeNode(root, val);
    }

    int getKthOrder(int k)
    {
        Node* currNode = this->root;
        int offset = 0;

        int nodeOrder;
        while(currNode)
        {
            nodeOrder = offset + currNode->sizes.first + 1;
            if(nodeOrder == k)
                return currNode->val;
            else if(nodeOrder > k)
                currNode = currNode->left;
            else
            {
                offset = nodeOrder;
                currNode = currNode->right;
            }
        }

        return 0;
    }

};

vector<double> medianSlidingWindow(vector<int>& nums, int k); 
void balanceSets(multiset<int>& left, multiset<int>& right);

int main()
{
    vector<int> nums = {1,2,3,4,2,3,1,4,2};
    //vector<int> nums = {5,2,2,7,3,7,9,0,2,3};
    //vector<int> nums = {1,3,-1,-3,5,3,6,7};

    vector<double> medians = medianSlidingWindow(nums, 3);
    for(int a = 0; a < medians.size(); ++a)
    {
        cout << medians[a] << ' ';
    }

    getchar();
    return 0;
}

vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    multiset<int> left;
    multiset<int> right;

    int i = 0;
    for(; i < k; ++i)
    {
        if(!left.size() || nums[i] < *left.rbegin())
            left.insert(nums[i]);
        else
            right.insert(nums[i]);
        
        balanceSets(left, right);
    }

    vector<double> medians;
    medians.reserve(max(nums.size()-k-1, 1ull));

    bool isEven = !(k % 2);
    do
    {
        if(isEven)
            medians.push_back(((double)*(left.rbegin()) + (double)*(right.begin())) / 2.0);
        else
            medians.push_back((double)*(left.rbegin()));

        if(nums[i-k] <= *left.rbegin())
            left.erase(left.find(nums[i-k]));
        else
            right.erase(right.find(nums[i-k]));

        balanceSets(left, right);
        if(i < nums.size())
        {
            if(!left.size() || nums[i] <= *left.rbegin())
                left.insert(nums[i]);
            else
                right.insert(nums[i]);
            balanceSets(left, right);
        }

    } while(++i <= nums.size());

    return medians;
}

void balanceSets(multiset<int>& left, multiset<int>& right)
{
    if((left.size() + right.size()) % 2)
    {
        //Odd length

        if(left.size() < right.size())
        {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    else
    {
        //Even length

        if(left.size() > right.size())
        {
            right.insert(*left.rbegin());
            left.erase(--left.end());
        }
        else if(right.size() > left.size())
        {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
}

/*vector<double> medianSlidingWindow(vector<int>& nums, int k) 
{
    AvlTree tree;

    int i = 0;
    for(; i < k; ++i)
    {
        tree.insertVal(nums[i]);
    }

    vector<double> medians;
    medians.reserve(k == nums.size() ? 1 : nums.size()-k-1);

    bool isEven = !(k % 2);
    int medianIndex = ceil(k/2.0);
    do
    {
        if(isEven)
            medians.push_back(((double)tree.getKthOrder(medianIndex) + (double)tree.getKthOrder(medianIndex+1)) / 2.0);
        else
            medians.push_back((double)tree.getKthOrder(medianIndex));

        tree.removeVal(nums[i-k]);
        if(i != nums.size())
            tree.insertVal(nums[i]);

    } while (++i <= nums.size());
    
    return medians;
}*/
