
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Tweet;


class Twitter 
{
private:
    unordered_map<int,unordered_set<int>> followingList;
    unordered_map<int,vector<Tweet>> tweets;
    int seqNumber;

    void generateUser(int userId)
    {
        unordered_map<int,vector<Tweet>>::iterator itr = tweets.find(userId);
        if(itr == tweets.end())
        {
            tweets[userId] = {};
            followingList[userId] = unordered_set<int>({userId});
        }
    }

public:
    Twitter() 
    {
        seqNumber = 1e4+1;    
    }
    
    void postTweet(int userId, int tweetId) 
    {
        generateUser(userId);

        tweets[userId].push_back(Tweet(seqNumber--, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        generateUser(userId);

        map<int,vector<int>> latestTweets;
        unordered_set<int>* following = &(followingList[userId]);
        for(unordered_set<int>::iterator itr = following->begin(); itr != following->end(); ++itr)
        {
            if(tweets[*itr].empty())
                continue;
            
            vector<Tweet>& userTweets = tweets[*itr];
            Tweet tweet = *(userTweets.rbegin());
            latestTweets[tweet.first] = {*itr,(int)userTweets.size()-1};
        }

        vector<int> feed;
        unordered_map<int,vector<Tweet>>::iterator itr;
        while(!latestTweets.empty() && feed.size() != 10)
        {
            map<int,vector<int>>::iterator currTweet = latestTweets.begin();
            feed.push_back(tweets[currTweet->second[0]][currTweet->second[1]].second);

            int i = currTweet->second[1] - 1;
            itr = tweets.find(currTweet->second[0]);
            if(i >= 0)
            {
                latestTweets[itr->second[i].first] = {currTweet->second[0],i};
            }

            latestTweets.erase(currTweet);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) 
    {
        generateUser(followerId);
        generateUser(followeeId);

        followingList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        unordered_map<int,unordered_set<int>>::iterator itr = followingList.find(followerId);
        if(itr != followingList.end())
            itr->second.erase(followeeId);
    }
};

int main()
{
    // Twitter tw;
    // tw.postTweet(1,5);
    // tw.getNewsFeed(1);
    // tw.follow(1,2);
    // tw.postTweet(2,6);
    // tw.getNewsFeed(1);
    // tw.unfollow(1,2);
    // tw.getNewsFeed(1);

    Twitter tw;
    tw.postTweet(1,5);
    tw.postTweet(1,3);
    tw.getNewsFeed(1);

    getchar();
    return 0;
}