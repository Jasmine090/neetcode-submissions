class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> re;
        unordered_map<string, int> key;
        int cur_key_idx = 0;
        for(int i=0;i<strs.size();i++){
            char count[26] = {0};
            for(int j=0;j<strs[i].size();j++){
                count[strs[i][j]-'a']++;
            }
            string tmp(count, 26);
            if(key.count(tmp)) re[key[tmp]].push_back(strs[i]);
            else{
                key[tmp] = cur_key_idx;
                vector<string> new_class{strs[i]};
                re.push_back(new_class);
                cur_key_idx++;
            }
        }
        return re;
    }
};
