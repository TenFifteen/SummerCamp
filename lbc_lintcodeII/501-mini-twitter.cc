/*
题目大意：
实现一个tweeter。

解题思路：
见代码。

遇到的问题：
C++中的静态函数的调用方法得用::域操作符，而不是.操作符。
在这里还搞了好一会。
另外就是，getNewsFeed这个函数实现的效率一般，可以用堆进行优化。
*/
/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
class MiniTwitter {
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    
    struct Cmp {
        bool operator() (const Tweet t1, const Tweet t2) const {
            return t1.id < t2.id;
        }
    };
    
public:
    MiniTwitter() {
        // initialize your data structure here.
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        tweets[user_id].push_back(Tweet::create(user_id, tweet_text));
        return tweets[user_id].back();
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        set<Tweet, Cmp> s;
        vector<Tweet> selfTweets = getTimeline(user_id);
        for (int i = 0; i< selfTweets.size(); ++i) {
            s.insert(selfTweets[i]);
        }
        
        for (auto id : follows[user_id]) {
            vector<Tweet> ret = getTimeline(id);
            for (int i = 0; i < ret.size(); ++i) {
                s.insert(ret[i]);
                if (s.size() > 10) {
                    s.erase(*s.begin());
                }
            }
        }
        
        vector<Tweet> ret;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            ret.push_back(*it);
        }
        return ret;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        // Write your code here
        vector<Tweet> ret;
        int n = tweets[user_id].size();
        for (int i = n-1; i >= max(0, n-10); --i) {
            ret.push_back(tweets[user_id][i]);
        }
        return ret;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        follows[from_user_id].insert(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        if (follows[from_user_id].find(to_user_id) != follows[from_user_id].end()) {
            follows[from_user_id].erase(to_user_id);
        }
    }
};
