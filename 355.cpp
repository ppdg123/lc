class Twitter {
public:
    struct post {
        int id;
        int tm;
    };
    static bool cmp(struct post a , struct post b) {
        return a.tm > b.tm;
    }
    Twitter() {
        tm = 0;
    }
    void postTweet(int userId, int tweetId) {
        posts_it = posts.find(userId);
        if (posts_it == posts.end()) {
            posts[userId] = vector<struct post>();
        }
        struct post p;
        p.id = tweetId;
        p.tm = tm;
        tm ++;
        posts[userId].push_back(p);
        follow(userId,userId);
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<struct post> ans_t;
        struct post p;
        follow_it = follows.find(userId);
        if (follow_it == follows.end()) return ans;
        for (f_it = follows[userId].begin(); f_it != follows[userId].end(); ++f_it) {
            int id = *f_it;
            for (int i = 0; i < posts[id].size(); ++i) {
                p = posts[id][i];
                ans_t.push_back(p);
            }
        }
        sort(ans_t.begin(),ans_t.end(),cmp);
        for (int i = 0; i < ans_t.size(); ++i) {
            if (i > 9) break;
            ans.push_back(ans_t[i].id);
        }
        return ans;
    }
    void follow(int followerId, int followeeId) {
        follow_it = follows.find(followerId);
        if (follow_it == follows.end()) {
            follows[followerId] = set<int>();
        }
        follows[followerId].insert(followeeId);
    }
   void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follow_it = follows.find(followerId);
        if (follow_it == follows.end()) {
            return;
        }
        f_it = follows[followerId].find(followeeId);
        if (f_it != follows[followerId].end()) {
            follows[followerId].erase(f_it);
        }
    }
    map<int,vector<struct post>> posts;
    map<int,vector<struct post>>::iterator posts_it;
    map<int,set<int>> follows;
    map<int,set<int>>::iterator follow_it;
    set<int>::iterator f_it;
    int tm;
};

