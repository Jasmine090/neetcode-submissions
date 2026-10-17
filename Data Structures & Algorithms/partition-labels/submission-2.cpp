class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, -1);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a'] = i;
        }
        int start = 0;
        int end = 0;
        vector<int> re;
        for(int i=0;i<s.size();i++){
            end = max(end, mp[s[i]-'a']);
            if(i==end){
                re.push_back(end-start+1);
                start = i+1;
            }
        }

        return re;
    }
};
