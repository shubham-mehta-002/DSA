#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    // userId -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> posts;

    // followerId -> followees
    unordered_map<int, unordered_set<int>> following;

    int time;

public:
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        posts[userId].push_back({++time, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {

        // {timestamp, {postIndex, userId}}
        // Max heap -> most recent tweet first
        using pp = pair<int, pair<int, int>>;

        priority_queue<pp> pq;

        // Add user's own latest tweet
        if (!posts[userId].empty())
        {

            int index = posts[userId].size() - 1;

            pq.push({posts[userId][index].first,
                     {index, userId}});
        }

        // Add latest tweet of every followed user
        for (int followee : following[userId])
        {

            if (!posts[followee].empty())
            {

                int index = posts[followee].size() - 1;

                pq.push({posts[followee][index].first,
                         {index, followee}});
            }
        }

        vector<int> result;

        // Get at most 10 most recent tweets
        while (!pq.empty() && result.size() < 10)
        {

            auto top = pq.top();
            pq.pop();

            int timestamp = top.first;
            int postIndex = top.second.first;
            int user = top.second.second;

            // Add tweet ID
            result.push_back(
                posts[user][postIndex].second);

            // Add next older tweet of same user
            if (postIndex > 0)
            {

                pq.push({posts[user][postIndex - 1].first,
                         {postIndex - 1, user}});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};