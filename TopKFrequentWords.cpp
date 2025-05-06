
#include<bits/stdc++.h>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k);

int main()
{
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    topKFrequent(words, 4);

    getchar();

    return 0;
}

vector<string> topKFrequent(vector<string>& words, int k) 
{
    auto cmp = [&words](pair<int,unordered_map<string,int>::iterator>& x, pair<int,unordered_map<string,int>::iterator>& y) -> bool {
        if(x.first == y.first)
            return x.second->first < y.second->first;
        return x.first > y.first;
    };
    priority_queue<pair<int,unordered_map<string,int>::iterator>,vector<pair<int,unordered_map<string,int>::iterator>>, decltype(cmp)> heap(cmp);

    unordered_map<string,int> freqs;
    for(int i = 0; i < words.size(); ++i)
    {
        freqs[words[i]]++;
    }

   for(unordered_map<string,int>::iterator itr = freqs.begin(); itr != freqs.end(); ++itr)
   {
        heap.push(pair<int,unordered_map<string,int>::iterator>(itr->second, itr));
        if(heap.size() > k)
            heap.pop();
   }

   vector<string> result;
   while(!heap.empty())
   {
        result.push_back(heap.top().second->first);
        heap.pop();
   }
   reverse(result.begin(), result.end());

    return result;
}