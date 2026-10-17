class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*
        x 0 3
        y 1 4
        z 5 7
        b 6 9
        i 10 10
        s 11 11
        l 12 12    
        */
        unordered_map<char, pair<int, int>> mp;
        for(int i=0;i<s.size();i++){
            if(!mp.count(s[i])){
                mp[s[i]] = {i, i};
            }
            else{
                mp[s[i]].second = i;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(const auto& a: mp){
            // cout << a.first << ' ' << a.second.first << ' ' << a.second.second << endl;
            pq.push(a.second);
        }
        int start = pq.top().first;
        int end = pq.top().second;
        pq.pop();
        vector<int> re;
        //cout << start << ' ' << end << endl;
        while(!pq.empty()){
            pair<int, int> tmp = pq.top();
            // cout << start << ' ' << end << endl;
            //cout << tmp.first << ' ' << tmp.second << endl;
            
            pq.pop();
            if(end < tmp.first){
                // cout << '*' << endl;
                re.push_back(end-start+1);
                start = tmp.first;
            }

            end = max(end, tmp.second);
            if(pq.empty()){
                re.push_back(end-start+1);
            }
        }
        return re;
    }
};
