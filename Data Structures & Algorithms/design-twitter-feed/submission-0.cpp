class Twitter {
private:
    int count;
    unordered_map<int, vector<pair<int,int>>> tweetMap;  // userId → [{timestamp, tweetId}]
    unordered_map<int, set<int>> followMap;

public:
    Twitter() : count(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // max-heap on timestamp — array<int,4> = {timestamp, tweetId, followeeId, index}
        auto cmp = [](const array<int,4>& a, const array<int,4>& b) {
            return a[0] < b[0];  // min-heap on timestamp — largest on top
        };
        priority_queue<array<int,4>, vector<array<int,4>>, decltype(cmp)> maxHeap(cmp);

        followMap[userId].insert(userId);  // always see your own tweets

        // seed heap with the newest tweet from each followee
        for (int followee : followMap[userId]) {
            if (tweetMap.count(followee)) {
                const auto& tweets = tweetMap[followee];
                int index = tweets.size() - 1;  // newest tweet
                maxHeap.push({tweets[index].first,   // timestamp
                              tweets[index].second,  // tweetId
                              followee,              // whose feed
                              index});               // position in their feed
            }
        }

        // k-way merge — always pop newest, push next from same feed
        while (!maxHeap.empty() && res.size() < 10) {
            auto [timestamp, tweetId, followee, index] = maxHeap.top();
            maxHeap.pop();

            res.push_back(tweetId);

            // push the next older tweet from the same followee
            if (index > 0) {
                const auto& tweets = tweetMap[followee];
                maxHeap.push({tweets[index-1].first,
                              tweets[index-1].second,
                              followee,
                              index - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);   // ✅ fixed typo
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};