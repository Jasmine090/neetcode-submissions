class Solution {
public:
    void DecisionTree(vector<int>& candidates, vector<int> cur, vector<vector<int>> &re, int start, int target){
        if(target == 0){
                re.push_back(cur);
                return;
        }

        for(int i=start; i<candidates.size(); i++){
            if(target < candidates[i]) return;
            if(i>start && candidates[i-1]==candidates[i]) continue;
            cur.push_back(candidates[i]);
            DecisionTree(candidates, cur, re, i+1, target-candidates[i]);
            cur.pop_back();
        }
    }
    //1,2,2,4,5,6,9
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> re;
        sort(candidates.begin(), candidates.end());
        DecisionTree(candidates, {}, re, 0, target);
        return re;
    }
};
