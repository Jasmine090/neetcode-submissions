class Solution {
public:
    void DecisionTree(vector<vector<char>> &mp, string &digits, string &cur, vector<string> &re){
        if(digits=="") return;
        if(cur.size()==digits.size()){
            re.push_back(cur);
            return;
        }
        int cur_idx = digits[cur.size()]-'1';
        // cout << cur_idx << endl;
        // cout << digits[cur_idx]-'1' << endl;
        for(int i=0;i<mp[cur_idx].size();i++){
            cur.push_back(mp[cur_idx][i]);
            DecisionTree(mp, digits, cur, re);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> mp {
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        vector<string> re;
        string cur = "";
        DecisionTree(mp, digits, cur, re);
        return re;
    }
};
