class Solution {
public:
    void DecisionTree(int n, int left_n, int left_cur, string &cur, vector<string> &re){
        if(cur.size()==2*n){
            re.push_back(cur);
            return;
        }
        if(left_n!=n){
            cur.push_back('(');
            DecisionTree(n, left_n+1, left_cur+1, cur, re);
            cur.pop_back();
        }
        if(left_cur!=0){
            cur.push_back(')');
            DecisionTree(n, left_n, left_cur-1, cur, re);
            cur.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> re;
        cur.push_back('(');
        DecisionTree(n, 1, 1, cur, re);
        return re;
    }
};
