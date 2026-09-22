class Solution {
public:
    void DecisionTree(vector<int> &nums, int start_idx, vector<int> cur, vector<vector<int>> &re){
        re.push_back(cur);
        for(int i=start_idx ; i<nums.size() ; i++){
            cur.push_back(nums[i]);
            DecisionTree(nums, i+1, cur, re);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re;
        DecisionTree(nums, 0, {}, re);
        return re;
    }
};
