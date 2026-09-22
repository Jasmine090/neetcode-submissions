class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 預處理：dp[i][j] 表示 s[i:j]（閉區間）是否為回文
        // 區間長度從小到大遞增，確保計算 dp[i][j] 時 dp[i+1][j-1] 已經算好
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<string> cur;
        vector<vector<string>> re;
        DFS(s, 0, dp, cur, re);
        return re;
    }

private:
    void DFS(string &s, int start, vector<vector<bool>> &dp,
             vector<string> &cur, vector<vector<string>> &re) {
        if (start >= s.size()) {
            re.push_back(cur);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) {   // O(1) 查表，取代原本的 is_palindrome 呼叫
                cur.push_back(s.substr(start, i - start + 1));
                DFS(s, i + 1, dp, cur, re);
                cur.pop_back();
            }
        }
    }
};