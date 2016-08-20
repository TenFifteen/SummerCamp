/*
 * ok
 */
class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int id;
public:
    /** Initialize your data structure here. */
    Twitter() {
        id = 1;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(id++, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        cout << "getting " << userId << endl;
        set<pair<int, int>> s;
        follows[userId].insert(userId); // read self tweets.
        for (auto f : follows[userId]) {
            if (tweets[f].size() == 0) continue;
            int last =tweets[f].size() >= 10 ? tweets[f].size()-10 : 0;
            for (int i = tweets[f].size()-1; i >= last; --i) {
                s.insert(tweets[f][i]);
                if (s.size() > 10) s.erase(*s.begin());
            }
        }

        vector<int> ans;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            ans.push_back(it->second);
        }

        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
