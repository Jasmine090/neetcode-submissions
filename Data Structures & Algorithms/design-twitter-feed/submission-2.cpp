class Twitter {
public:
    int clk = 0;
    map<int, vector<pair<int, int>>> tweets; // User id, <tweets id, post clk>
    map<int, set<int>> follows; // User id, followed id
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, clk});
        clk++;
    }
    
    vector<int> getNewsFeed(int userId) {
        if(!follows[userId].count(userId)) follows[userId].insert(userId);
        vector<int> re;
        map<int, int> idx;
        //cout << userId << ' ';
        for(const auto &a:follows[userId]){
            if(tweets[a].size()>0){
                idx[a] = tweets[a].size()-1;
                //cout << a << ' ';
            }
            //cout << a << ':' << tweets[a].size() << ' ';
        }
        //cout << endl;
        int comp_n = idx.size();
        // cout << comp_n << endl << endl; 
        for(int i=0;i<10;i++){
            if(!comp_n) break;
            int latest[3] = {0, 0, -1}; //user id, tweet id, clk
            for(const auto &a:follows[userId]){
                if(idx.count(a) && idx[a]>=0 && latest[2] < tweets[a][idx[a]].second){
                    //cout << latest[1] << ' ';
                    latest[0] = a;
                    latest[1] = tweets[a][idx[a]].first;
                    latest[2] = tweets[a][idx[a]].second;
                    cout << latest[1] << ", " << latest[2] <<", ";
                }
                //cout << endl;
            }
            
            re.push_back(latest[1]);
            idx[latest[0]]--;
            if(idx[latest[0]]==-1) comp_n--;
        }
        //cout << endl;
        return re;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
