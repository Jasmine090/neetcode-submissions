class Solution {
public:
    void DecisionTree(int n, int former_n, int to_fill, string &cur, vector<string> &re){
        if(cur.size()==2*n){
            re.push_back(cur);
            return;
        }
        if(former_n==n){
            cur.push_back(')');
            DecisionTree(n, former_n, to_fill-1, cur, re);
            cur.pop_back();
        }
        else if(to_fill==0){
            cur.push_back('(');
            DecisionTree(n, former_n+1, to_fill+1, cur, re);
            cur.pop_back();
        }
        else{
            cur.push_back('(');
            DecisionTree(n, former_n+1, to_fill+1, cur, re);
            cur.pop_back();
            cur.push_back(')');
            DecisionTree(n, former_n, to_fill-1, cur, re);
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
