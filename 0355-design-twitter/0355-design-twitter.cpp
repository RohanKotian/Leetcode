class Twitter {
public:
    struct Node{
        int time;
        int tweetId;
        int userId;
        int index;

        Node(int t, int tId, int uId, int idx){
            time = t;
            tweetId = tId;
            userId = uId;
            index = idx;     
        }
    };

    struct Compare{
        bool operator()(const Node& a, const Node& b){
            return a.time < b.time;
        }
    };

    Twitter() {}
    
    unordered_map<int, set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    
    int time = 0;

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);

        priority_queue<Node, vector<Node>, Compare> feed;

        for(int user:following[userId]){
            if(!tweets[user].empty()){
                int ind = tweets[user].size() - 1;

                feed.push(Node(
                    tweets[user][ind].first,
                    tweets[user][ind].second,
                    user,
                    ind
                ));
            }
        }

        vector<int> res;
        while(!feed.empty() && res.size() < 10){
            Node top = feed.top();
            feed.pop();

            int tweetId = top.tweetId;
            int user = top.userId;
            int ind = top.index - 1;

            res.push_back(tweetId);

            if(ind>=0){
                feed.push(Node(
                    tweets[user][ind].first,
                    tweets[user][ind].second,
                    user,
                    ind
                ));
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */