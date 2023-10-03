
#include<bits/stdc++.h>

using namespace std;

class DLN {
public:
    int key;
    int val;
    DLN* next;
    DLN* prev;
    DLN(int key, int v) : key(key), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache 
{
private:
    const int capacity;
    int currSize;
    DLN* cacheHead;
    DLN* cacheTail;
    unordered_map<int,DLN*> cacheMap;

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        this->currSize = 0;
        cacheHead = new DLN(-1,0);
        cacheTail = new DLN(-1,1);
        cacheHead->next = cacheTail;
        cacheTail->prev = cacheHead;
    }
    
    int get(int key) 
    {
        unordered_map<int,DLN*>::iterator itr = cacheMap.find(key);
        if(itr == cacheMap.end())
            return -1;
        
        DLN* keyNode = itr->second;

        keyNode->next->prev = keyNode->prev;
        keyNode->prev->next = keyNode->next;
        keyNode->prev = cacheTail->prev;
        cacheTail->prev->next = keyNode;
        keyNode->next = cacheTail;
        cacheTail->prev = keyNode;

        return keyNode->val;
    }
    
    void put(int key, int value) 
    {
        unordered_map<int,DLN*>::iterator itr = cacheMap.find(key);
        if(itr == cacheMap.end())
        {
            if(currSize == capacity)
            {
                DLN* evictedNode = cacheHead->next;
                cacheHead->next = evictedNode->next;
                evictedNode->next->prev = cacheHead;
                cacheMap.erase(evictedNode->key);
                delete evictedNode;
            }

            DLN* newNode = new DLN(key,value);
            newNode->prev = cacheTail->prev;
            newNode->next = cacheTail;
            cacheTail->prev->next = newNode;
            cacheTail->prev = newNode;
            cacheMap[key] = newNode;
            currSize = min(currSize+1,capacity);

            return;
        }

        DLN* keyNode = itr->second;
        keyNode->val = value;

        keyNode->next->prev = keyNode->prev;
        keyNode->prev->next = keyNode->next;
        keyNode->prev = cacheTail->prev;
        cacheTail->prev->next = keyNode;
        keyNode->next = cacheTail;
        cacheTail->prev = keyNode;
    }
};


int main()
{
    /*LRUCache lruCache(2);
    lruCache.put(1,1);
    lruCache.put(2,2);
    cout << lruCache.get(1) << '\n';
    lruCache.put(3,3);
    cout << lruCache.get(2) << '\n';
    lruCache.put(4,4);
    cout << lruCache.get(1) << '\n';
    cout << lruCache.get(3) << '\n';
    cout << lruCache.get(4) << '\n';*/

    LRUCache lruCache(1);
    lruCache.put(2,1);
    cout << lruCache.get(2) << '\n';
    lruCache.put(3,2);
    cout << lruCache.get(2) << '\n';
    cout << lruCache.get(3) << '\n';

    getchar();
    return 0;
}


/*
class LRUCache 
{
private: 
    const int capacity;
    int currSize;
    unordered_map<int,LN*> cacheMap;
    LN* cacheHead;
    LN* cacheTail;

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        this->currSize = 0;
        cacheHead = new LN(-1,-1);
        cacheTail = cacheHead;
    }
    
    int get(int key) 
    {
        unordered_map<int,LN*>::iterator itr = cacheMap.find(key);
        if(itr == cacheMap.end())
            return -1;
        
        int keyVal = itr->second->next->val;
        
        LN* keyNode = itr->second->next;
        if(keyNode != cacheTail)
        {
            itr->second->next = keyNode->next;
            if(keyNode->next)
                cacheMap[keyNode->next->key] = itr->second;
            cacheTail->next = keyNode;
            itr->second = cacheTail;
            cacheTail = keyNode;
            cacheTail->next = nullptr;
        }

        return keyVal;
    }
    
    void put(int key, int value) 
    {
        unordered_map<int,LN*>::iterator itr = cacheMap.find(key);
        if(itr == cacheMap.end())
        {
            if(currSize == capacity)
            {
                LN* keyNode = cacheHead->next;
                cacheMap.erase(keyNode->key);
                cacheHead->next = keyNode->next;
                if(keyNode->next)
                    cacheMap[keyNode->next->key] = cacheHead;
                delete keyNode;
            }
            cacheMap[key] = cacheTail;
            cacheTail->next = new LN(key,value);
            cacheTail = cacheTail->next;
            currSize += 1*(currSize != capacity);
        }
        else {
            LN* keyNode = itr->second->next;
            if(keyNode != cacheTail)
            {
                itr->second->next = keyNode->next;
                if(keyNode->next)
                    cacheMap[keyNode->next->key] = itr->second;
                cacheTail->next = keyNode;
                itr->second = cacheTail;
                cacheTail = keyNode;
                cacheTail->next = nullptr;
            }

            keyNode->val = value;
        }
    }
};
*/
