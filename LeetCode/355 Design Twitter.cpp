/*
 题意是希望你设计一个简单的结构.
 里面能够实现发送tweet，follow sb，unfollow sb.
 然后取当前自己和自己follow的人里面最新的10条tweet.
 后来想了一下，写的还是不好，应该把每一个用户，写成一个struct。把每一个tweet写成一个struct。
 对于返回最新的10条信息，把所有信息放到优先队列里，弹出10个即可。
 */
struct no
{
    int num;
    int tim;
    bool operator<(const no& x)const
    {
        return tim < x.tim;
    }
};

class Twitter {
    int ti = 0;
    map<int, vector<int>>foll;
    map<int, vector<no>>tweet;
public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        tweet[userId].push_back({ tweetId,ti++ });
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int>f = foll[userId];
        priority_queue<no>que;
        for (auto user : f)
        {
            for (auto it : tweet[user])
            {
                que.push(it);
            }
        }
        for (auto it : tweet[userId])
        {
            que.push(it);
        }
        int sz = 0;
        vector<int>re;
        while (!que.empty())
        {
            no tmp = que.top();
            que.pop();
            re.push_back(tmp.num);
            sz++;
            if (sz == 10)
            {
                break;
            }
        }
        //reverse(re.begin(), re.end());
        return re;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
        {
            return;
        }
        int sz = foll[followerId].size();
        for (int i = 0; i < sz; i++)
        {
            if (foll[followerId][i] == followeeId)
            {
                return;
            }
        }
        foll[followerId].push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        for (vector<int>::iterator it = foll[followerId].begin(); it != foll[followerId].end(); it++)
        {
            if (*it == followeeId)
            {
                foll[followerId].erase(it);
                return;
            }
        }
    }
};