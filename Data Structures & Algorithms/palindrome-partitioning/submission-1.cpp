class Solution {
public:
    bool is_palindrome(const string &s, int left, int right){
        while(left < right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void DFS(string &s, int start, vector<string> &cur, vector<vector<string>> &re){
        if(start>=s.size()){
            re.push_back(cur);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(is_palindrome(s, start, i)){
                cur.push_back(s.substr(start, i-start+1));
                DFS(s, i+1, cur, re);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> re;
        DFS(s, 0, cur, re);
        return re;
    }
};
